.data
// 
// Create a stack frame and store 
// some values in it
// 
  .equ f_src, 16      // Source image
  .equ f_dest, 24     // Destination image 
  .equ f_wid, 32
  .equ f_hit, 36
  .equ f_size, 48

.text

.global blocky
//
// void *blocky(void *src)
//
blocky:
    fp  .req x29
    lr  .req x30
            
    //
    // Create a stack frame and store 
    // some values in it
    //
    //.equ f_src, 16      // Source image
    //.equ f_dest, 24     // Destination image
    //.equ f_wid, 32
    //.equ f_hit, 36
    //.equ f_size, 48
                                   
    stp fp, lr, [sp, #-f_size]!
    mov fp, sp

    stp x19, x20, [sp, #-16]!
    stp x21, x22, [sp, #-16]!
                                                
    str x0, [fp, #f_src]
    
    
    
    ldr x0, [fp, #f_dest]
         
    ldp x21, x22, [sp], #16
    ldp x19, x20, [sp], #16
    ldp fp, lr, [sp], #f_size
    ret
