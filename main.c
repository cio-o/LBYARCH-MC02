#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <malloc.h>

float dotproduct_c(float* A, float* B, int n);
extern float dotproduct_asm(float* A, float* B, int n);

double get_time() {
    LARGE_INTEGER frequency, counter;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&counter);
    return (double)counter.QuadPart / (double)frequency.QuadPart;
}

int main() {
    int sizes[] = { 1 << 20, 1 << 24, 1 << 28 };
    const char* size_labels[] = { "20", "24", "28" };
    int num_sizes = 3;
    int num_runs = 30; 

    printf("DOT PRODUCT SIMD PERFORMANCE\n");
    printf("Scalar SIMD instructions (movss, mulss, addss)\n");
    printf("Number of runs per test: %d\n", num_runs);

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        printf("TEST %d: Vector size n = 2^%s (%d elements)\n", s + 1, size_labels[s], n);

        float* A = (float*)_aligned_malloc(n * sizeof(float), 16);
        float* B = (float*)_aligned_malloc(n * sizeof(float), 16);

        if (A == NULL || B == NULL) {
            printf("Memory allocation failed for n = %d\n", n);
            if (A) _aligned_free(A);
            if (B) _aligned_free(B);
            continue;
        }

        srand(12345);
        for (int i = 0; i < n; i++) {
            A[i] = (float)(rand() % 100) / 10.0f;
            B[i] = (float)(rand() % 100) / 10.0f;
        }

        float sdot_c = 0.0f;
        double total_time_c = 0.0;

        for (int run = 0; run < num_runs; run++) {
            double start = get_time();
            sdot_c = dotproduct_c(A, B, n);
            double end = get_time();
            total_time_c += (end - start);
        }

        double avg_time_c = total_time_c / num_runs;

        float sdot_asm = 0.0f;
        double total_time_asm = 0.0;

        for (int run = 0; run < num_runs; run++) {
            double start = get_time();
            sdot_asm = dotproduct_asm(A, B, n);
            double end = get_time();
            total_time_asm += (end - start);
        }

        double avg_time_asm = total_time_asm / num_runs;

        float diff = fabsf(sdot_c - sdot_asm);
        float relative_error = diff / fabsf(sdot_c);
        int is_correct = (relative_error < 1e-5);

        printf("C RESULTS\n");
        printf("Result (sdot):      %20.6f \n", sdot_c);
        printf("Average time:       %20.9f sec\n", avg_time_c);
        printf("\n");

        printf("x86-64 ASSEMBLY RESULTS\n");
        printf("Result (sdot):      %20.6f\n", sdot_asm);
        printf("Average time:       %20.9f sec\n", avg_time_asm);

        printf("CORRECTNESS CHECK\n");
        printf("Absolute Diff:      %20.9f \n", diff);
        printf("Relative Error:     %20.9f\n", relative_error);
        printf("Correct?:             %20s \n", is_correct ? "YES" : "NO");

        printf("PERFORMANCE COMPARISON\n");
        printf("Speedup (C/ASM):    %20.4fx \n", avg_time_c / avg_time_asm);
        
        double perf_diff = fabs((avg_time_asm - avg_time_c) / avg_time_c * 100);
        const char* faster = (avg_time_asm < avg_time_c) ? "faster" : "slower";
        printf("Assembly is %5.2f%% %-8s than C\n", perf_diff, faster);
        printf("END\n");


        _aligned_free(A);
        _aligned_free(B);
    }

    return 0;
}

float dotproduct_c(float* A, float* B, int n) {
    float sdot = 0.0f;
    
    for (int i = 0; i < n; i++) {
        sdot += A[i] * B[i];
    }
    
    return sdot;
}