.text

x :  .double 0
y : .double 0
four : .double 4.0
.global ship
ship:    
    stp x17, x18, [sp, #-16]!
    ldr x2,= x
    ldr d2, [x2]
    ldr d3, [x2]
    ldr d4, [x2]
    mov w2, #0
    ldr x3,= four
    ldr d5, [x3]

loop:
  fmul d6, d2, d2
  fmul d7, d3, d3
  fadd d8, d6, d7
 
  fcmp d8, d5
  bge loop_end

  cmp w2, #255
  bge loop_end

  fcmp d2, d4
  bge y_itr
  fsub d2, d4, d2

y_itr:
  fcmp d3, d4
  bge loop_count
  fsub d3, d4, d3

loop_count:
  fmul d6, d2, d2
  fmul d7, d3, d3
  fsub d9, d6, d7
  fadd d9, d9, d0
  fmul d10, d2, d3
  fadd d10, d10, d10
  fadd d10, d10, d1

  fmov d2, d9
  fmov d3, d10

  add w2, w2, #1
  b loop

loop_end:
 mov w0, w2
 ldp x17, x18, [sp], #16
 ret
