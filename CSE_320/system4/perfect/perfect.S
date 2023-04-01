.text
.global perfect_sqr


/**
 * Determine if a number is a perfect square.
 * x0 - Passed in value: num
 * Returns 1 if num is a perfect square.
*/
perfect_sqr:
   mov x1, #1
   mov x2, #1
   mov x3, #1
   lsl x3, x3, #32

forloop:
   cmp x1, x3
   beq loopend

   cmp x2, x0
   beq loopend

   cmp x2, x0
   bgt large

   add x2, x2, x1
   add x2, x2, x1
   add x2, x2, #1
   add x1, x1, #1
   b forloop
   
   mov x0, #1
   ret

large:
   mov x0,#0
   ret
loopend:
  mov x0, #1
  ret

