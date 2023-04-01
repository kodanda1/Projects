.data


.text

.global digitcounter

/**
 * unsigned int digitcounter(unsigned long value)
 * Returns the number of digits in the value
 */
digitcounter:
    fp .req x29
    lr .req x30
            
    .equ value, 16      // dword, Must start at 16 (after fp, lr)
    .equ quotient, 24   // dword
    .equ remainder, 32  // dword
    .equ counter, 40    // word (4 bytes)
    .equ size, 48       // Must be multiple of 16!
                                
    // Store fp and lr and makes space on the stack
    stp fp, lr, [sp, #-size]!
    mov fp, sp
                                        
   // Save value as local variable
   str x0,[fp,#value]
                                            
  // Variable to compute the size into
  mov w0, #0
  str w0, [fp, #counter]
                                                    
digitcounter_loop:    
    ldr w0, [fp, #value]
    cmp w0, #0
    beq digitcounter_done
    ldr w0, [fp, #counter]
    add w0, w0, #1
    str w0, [fp, #counter]
               
    ldr x0, [fp,#value]
    mov x1, #10
    bl ldiv
                           
    str x0, [fp, #quotient]
    str x1, [fp, #remainder]
                                   
    ldr x0, [fp, #quotient]
    str x0, [fp, #value]
    b digitcounter_loop
                                               
    // Get a result to return
    ldr x0, [fp, #quotient]
                                                       
digitcounter_done:
    ldr w0, [fp, #counter]
                                                       
    // Pop lr and fp and free stack space
    ldp x29, x30, [sp], #size
    ret
