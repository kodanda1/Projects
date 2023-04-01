//
// Data section
//
.data

//
// Messages
//
usagemsg:
    .asciz "Usage: guess [number]\n"

    splash:
        .asciz "We are guessing the number %d\n"
//
// Input buffer
//
    .set BUFFERSIZE,100
buffer:
   .space BUFFERSIZE,0
            
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
    stp x29, x30, [sp, #-16]!    // Push fp and lr onto the stack
    stp x19, x20, [sp, #-16]!   // Push x19 and x20 onto the stack
    cmp w0,#2
    blt usage
    // Determine the number to guess
    add x1,x1,#8    // Move to the second string
    ldr x0,[x1]     // Get the pointer to the actual string
    bl atoi         // Convert to an integer
    mov w19, w0  // Save value to guess into register w19
                    
    //
    // Splash
    //
    mov w1, w0
    ldr x0,=splash
    bl printf
loop:
    // fgets(buffer, sizeof(buffer), stdin)
    ldr x0,=buffer      // Argument 1: buffer address
    ldr x1,=BUFFERSIZE  // Argument 2: size of the buffer
    ldr x2,=stdin       // Address of stdin variable in memory
    ldr x2,[x2]         // Argument 3: value of stdin
    bl fgets
    //
    // Convert to an integer
    //
    ldr x0,=buffer
    bl atoi
    // Test it
    cmp w0, w19
    blt toolow
    bgt toohigh
                
    mov w0,#0
main_return:
    ldp x19, x20, [sp], #16     // Restore x19 and x20 from the stack
    ldp x29, x30, [sp], #16     // Restore fp and lr from the stack

        ret
// Guess was too low
toolow:
    b loop

// Guess was too high
toohigh:
    b loop
usage:
     ldr x0,=usagemsg
     bl printf
     mov w0,#1
     b main_return
