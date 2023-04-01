//
// Data section
//
.data

usage:  .asciz "Usage: sieve <size>\n";
minsize: .asciz "Sieve size must be at least 2\n"
primes: .asciz "Primes:"

return: .asciz "\n"

number: .asciz " %d"
//
// Text section
//

.text

.global main

//
// main(argc, argv)
// w0: The number of arguments
// x1: Pointer to an array of string pointers
// 
main: 
    stp x29, x30, [sp, #-16]!   // Push fp and lr onto the stack
    stp x19, x20, [sp, #-16]!   // Push x19 and x20 onto the stack
    stp x21, x22, [sp, #-16]!   // Push x21 and x22 onto the stack
     cmp w0,#2           // Compare argc to 2
     bge args_ok         // Branch if argc >= 2
             
     ldr x0,=usage       // Get address of message
     bl printf           // printf
                     
     mov w0,#1           // Return value: 1
     b main_return       // return
                             
args_ok: 
    ldr x0,[x1,#8]      // Get argv[1]
    bl atoi
     cmp w0,#2
     bge size_ok

     ldr x0,=minsize     // "Sieve size must be at least 2\n";
     bl printf           // printf
                     
     mov w0,#1           // Return value: 1
     b main_return       // return

size_ok:
      size .req w19       // Use w19 for size
      mov size, w0        // size
              
      add w0, size, #1    // w0 <- size+1
      mov w1, #4          // Size of an integer
      bl calloc           // calloc
      sieve .req x20
      mov sieve, x0       // Save the result
      mov x0, sieve 
      mov w1, size    
      bl display          // display(sieve, size)     
                                  
      mov x0, sieve
      bl free             // free
      mov x0, #0
    
main_return:
    ldp x21, x22, [sp], #16     // Restore x21 and x22 from the stack
    ldp x19, x20, [sp], #16     // Restore x19 and x20 from the stack
    ldp x29, x30, [sp], #16     // Restore fp and lr from the stack
    ret
   .unreq size
   .unreq sieve
//
// display(int *sieve, int size)
// x0: Pointer to an array of integers
// w1: Size of the array
// 
display: 
     stp x29, x30, [sp, #-16]!   // Push fp and lr onto the stack
     stp x19, x20, [sp, #-16]!   // Push x19 and x20 onto the stack
     stp x21, x22, [sp, #-16]!   // Push x21 and x22 onto the stack
     size .req w19               // Use w19 for size
     sieve .req x20              // Use x20 for the array
     mov size, w1
     mov sieve, x0

     ldr x0,=primes
     bl printf

    
     i .req w21                  // Use w21 for the loop counter
     mov i, #2
    
display_loop:
    cmp i,size
    bgt display_loop_end
    lsl w1, i, #2               // i * 4
    ldr w0, [sieve, w1, uxtw]   // sieve[i]

    cmp w0,#0                   // sieve[i] == 0?
    beq display_skip            // Yes, skip
    
    // printf(" %d", number)
    ldr x0,=number
    mov w1,i
    bl printf
    
display_skip:
    add i,i,#1
    b display_loop
                                
display_loop_end:  
    ldr x0,=return
    bl printf
              
display_return:
    ldp x21, x22, [sp], #16     // Restore x21 and x22 from the stack
    ldp x19, x20, [sp], #16     // Restore x19 and x20 from the stack
    ldp x29, x30, [sp], #16     // Restore fp and lr from the stack
    ret
     .unreq size
     .unreq sieve
     .unreq i 
//
// initialize(int *sieve, int size)
// x0: Pointer to an array of integers
// w1: Size of the array
// 
initialize: 
    stp x29, x30, [sp, #-16]!   // Push fp and lr onto the stack
    stp x19, x20, [sp, #-16]!   // Push x19 and x20 onto the stack
    stp x21, x22, [sp, #-16]!   // Push x21 and x22 onto the stack
         
    size .req w19               // Use w19 for size
    sieve .req x20              // Use x20 for the array
    mov size, w1
    mov sieve, x0
                   
    i .req w21
    mov i, #2
                       
initialize_loop:
    cmp i, size
    bgt initialize_loop_end
                         
    mov w0, #1
    lsl w1, i, #2               // i * 4
    str w0, [sieve, w1, uxtw]   // sieve[i]
                               
    add i, i, #1
    b initialize_loop
                                   
initialize_loop_end:
                                 
init_done:
    ldp x21, x22, [sp], #16     // Restore x21 and x22 from the stack
    ldp x19, x20, [sp], #16     // Restore x19 and x20 from the stack
    ldp x29, x30, [sp], #16     // Restore fp and lr from the stack
    ret  


    .unreq size
    .unreq sieve
    .unreq i
