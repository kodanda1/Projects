
.data
  .equ image_w, 0
  .equ image_h, 4
  .equ image_array, 8
  .equ image_size, 16
  .equ pixel_size, 8
  .equ cell_size, 8 
.text
 
.global create_image
//
// void *create_image(int wid, int hit)
// Create an image ADT and return it.
//
create_image:
  stp x29, x30, [sp, #-16]!
  stp x19, x20, [sp, #-16]!
  stp x21, x22, [sp, #-16]!
  mov w19, w0
  mov w20, w1 
	mov w0, #0
  mov w1, #image_size
  bl calloc
  str w19,[x0, #image_w]
  str w20,[x0, #image_h]
  mov x21, x0  
  mul w0, w19, w20  
  mov w1,#pixel_size
  bl calloc
  str x0,[x21,#image_array]
  mov x0,x21
  ldp x21, x22, [sp], #16
  ldp x19, x20, [sp], #16
  ldp x29, x30, [sp], #16
  ret
    
    
.global destroy_image   
//
// void destroy_image(void *image)
// Destroy image, freeing memory
//
destroy_image:
   stp x29,x30,[sp,#-16]!
   stp x19,x20,[sp,#-16]!
   mov x19,x0
   ldr x0,[x19,#image_array]
   bl free
   mov x0, x19
   bl free
   ldp x19,x20,[sp],#16
   ldp x29,x30,[sp],#16
   ret
    
    
.global get_width
//
// int get_width(void *image)
// Get the width of the image
//
get_width:
    ldr w0,[x0,#image_w]
    ret
    
.global get_height
//
// int get_height(void *image)
// Get the height of the image
//
get_height:
    ldr w0,[x0,#image_h]
    ret
    
        
.global set_pixel
//
// void set_pixel(void *image, int row, int col, double value)
//
set_pixel:
   stp x29, x30, [sp, #-16]!
   stp x19, x20, [sp, #-16]!
   mov w4,#pixel_size
   mul w1, w1, w3
   add w1, w1, w2
   mul w1, w1, w4
   ldr x4, [x0, #image_array]
   add x4,x4,w1,uxtw
   mov x0,x4
   str d0,[x0]
   ldp x19,x20, [sp], #16
   ldp x29, x30, [sp], #16
   ret

.global get_pixel
//
// double get_pixel(void *image, int row, int col)
//
get_pixel:
	ldr d0,  = 0
   stp x29,x30,[sp,#-16]!
   stp x19,x20,[sp,#-16]!
   mov w4, #pixel_size
   mul w1, w1, w4
   mov x0,x4
   ldr d0,[x0]
   ldp x19,x20,[sp],#16
   ldp x29,x30,[sp],#16
   ret

.global image_index
image_index:
    ldr w3,[x0, #image_w]
    mul w1, w1, w3
    add w1, w1, w2
    mov w2, #cell_size
    mul w1, w1, w2
    ldr x0, [x0, #image_array]
    add x0, x0, w2, uxtw
    ret
