# LBYARCH-MC02
Using C and an x86-64 assembly language, the kernel is to perform a dot product between vector A and vector B and place the result in sdot. 30 runs were conducted per test (20, 24, 28).


## PERFORMANCE RESULT
### DEBUG MODE

---

#### Vector Size: 2^20 (1,048,576 elements)

| Kernel | Average Time (sec) | Result (sdot)     | Correctness |
|--------|-----------------|-----------------|------------|
| C      | 0.006930373     | 25,637,680.000000 | CORRECT    |
| ASM    | 0.001792093     | 25,637,680.000000 | CORRECT    |

**Performance Comparison:**  
Speedup (C/ASM): 3.8672x — Assembly is 74.14% faster than C

---

#### Vector Size: 2^24 (16,777,216 elements)

| Kernel | Average Time (sec) | Result (sdot)      | Correctness |
|--------|-----------------|------------------|------------|
| C      | 0.111622090     | 399,363,232.000000 | CORRECT    |
| ASM    | 0.029620957     | 399,363,232.000000 | CORRECT    |

**Performance Comparison:**  
Speedup (C/ASM): 3.7683x — Assembly is 73.46% faster than C

---

#### Vector Size: 2^28 (268,435,456 elements)

| Kernel | Average Time (sec) | Result (sdot)       | Correctness |
|--------|-----------------|------------------|------------|
| C      | 1.781938043     | 2,147,483,648.000000 | CORRECT    |
| ASM    | 0.455620017     | 2,147,483,648.000000 | CORRECT    |

**Performance Comparison:**  
Speedup (C/ASM): 3.9110x — Assembly is 74.43% faster than C



### RELEASE MODE

---

#### Vector Size: 2^20 (1,048,576 elements)

| Kernel | Average Time (sec) | Result (sdot)     | Correctness |
|--------|-----------------|-----------------|------------|
| C      | 0.001842983     | 25,637,680.000000 | CORRECT    |
| ASM    | 0.001846597     | 25,637,680.000000 | CORRECT    |

**Performance Comparison:**  
Speedup (C/ASM): 0.9980x — Assembly is 0.20% slower than C

---

#### Vector Size: 2^24 (16,777,216 elements)

| Kernel | Average Time (sec) | Result (sdot)      | Correctness |
|--------|-----------------|------------------|------------|
| C      | 0.028620280     | 399,363,232.000000 | CORRECT    |
| ASM    | 0.028777810     | 399,363,232.000000 | CORRECT    |

**Performance Comparison:**  
Speedup (C/ASM): 0.9945x — Assembly is 0.55% slower than C

---

#### Vector Size: 2^28 (268,435,456 elements)

| Kernel | Average Time (sec) | Result (sdot)       | Correctness |
|--------|-----------------|------------------|------------|
| C      | 0.457456323     | 2,147,483,648.000000 | CORRECT    |
| ASM    | 0.472546600     | 2,147,483,648.000000 | CORRECT    |

**Performance Comparison:**  
Speedup (C/ASM): 0.9681x — Assembly is 3.30% slower than C


## ANALYSIS
