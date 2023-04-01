.data

.balign 8

one:    .double 1
three:  .double 3
.text
.global bezier

//
// double bezier(double t)
// Computes: 3 * (1-t)^2 * t
//
bezier:
    stp x29, x30, [sp, #-16]!
    fmov d1, d0     // Save t   
    ldr x0,=one
    ldr d2,[x0]     // d2=1
    fsub d2, d2, d1 // d2=1-t
    fmul d2, d2, d2 // d2=(1-t)^2    
    fmul d2, d2, d1 // d2=(1-t)^2 * t
    ldr x0,=three
    ldr d0,[x0]     // d0=3
                
    fmul d0, d0, d2 // d0=3 * (1-t)^2 * t
    
bezier_done:
    ldp x29, x30, [sp], #16
    ret             // return
