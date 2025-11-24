# LBYARCH-MC02
Using C and an x86-64 assembly language, the kernel is to perform a dot product between vector A and vector B and place the result in sdot.


## PERFORMANCE RESULT
### DEBUG MODE
### Vector Size 2^20

| Kernel   | Average Time (s)| Result (sdot) | Correct? |
|----------|-----------------|---------------|----------|
| C        | 0.0318          | 2.745382      | N/A      |
| ASM      | 0.0147          | 2.745382      | YES      |
     

### Vector Size 2^24

| Kernel | Average Time (s) | Result (sdot) | Correct? |
|--------|-----------------|---------------|----------|
| C      | 0.4987          | 4.398148      | N/A      |
| ASM    | 0.2305          | 4.398148      | YES      |
         

### Vector Size 2^28

| Kernel | Average Time (s) | Result (sdot) | Correct? |
|--------|-----------------|---------------|----------|
| C      | 7.9771          | 6.991018      | N/A      |
| ASM    | 3.5198          | 6.991018      | YES      |
      


### RELEASE MODE
### Vector Size 2^20

| Kernel | Average Time (s) | Result (sdot) | Correct? |
|--------|-----------------|---------------|----------|
| C      | 0.0132          | 2.745382      | N/A      |
| ASM    | 0.0147          | 2.745382      | YES      |
         

### Vector Size 2^24

| Kernel | Average Time (s) | Result (sdot) | Correct? |
|--------|-----------------|---------------|----------|
| C      | 0.2121          | 4.398148      | N/A      |
| ASM    | 0.2305          | 4.398148      | YES      |


### Vector Size 2^28

| Kernel | Average Time (s) | Result (sdot) | Correct? |
|--------|-----------------|---------------|----------|
| C      | 3.4112          | 6.991018      | N/A      |
| ASM    | 3.5198          | 6.991018      | YES      |          



## ANALYSIS
For debug mode, ASM is faster than C for large vectors (24, 28) showing that it has a performance advantage over C while in release mode, C slightly outpermorms asm for both the small and large vectors. For correctness, all tests produced identical results regardless of the size. Overall, ASM seems to do better in debug builds while C performs better in relase mode.