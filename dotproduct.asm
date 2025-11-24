section .text
global dotproduct_asm

dotproduct_asm:
    xorps xmm0, xmm0            ; XMM0 = 0.0 (sdot = 0.0)
    
    ; Check if n <= 0 (empty vector)
    test r8d, r8d               
    jle .done                  
    
    ; Initialize loop counter
    xor rax, rax                
    
.loop:
    movss xmm1, dword [rcx + rax*4]     
    movss xmm2, dword [rdx + rax*4]     
    mulss xmm1, xmm2                    
    addss xmm0, xmm1   

    inc rax                         
    cmp rax, r8                          
    jl .loop                            

.done:

    ret                             
