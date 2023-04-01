// 
// Simple program that adds four numbers
//
 
.text

.global add4


add4:
    add x2, x2, x3  // r2 = r2 + r3
    add x0, x0, x1  // r0 = r0 + r1
    add x0, x0, x2  // r0 = r0 + r2
    add x0, x0, x0
    ret     // return
    
