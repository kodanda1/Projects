.data


.text

.global life

//
// life iteration calculator
// x0 - int *cells
// w1 - int width in words
// w2 - int height in rows
//
life:
  stp x29, x30, [sp, #-16]!   
  stp x19, x20, [sp, #-16]!   
  stp x21, x22, [sp, #-16]!   

  data .req x20
  mov data, x0

  size .req w19
  mul size,w1,w2
  size .req w19
  mul size,w1,w2
  mov w3,#32
  mul size,size,w3

  add w0, size, #1
  mov w1, #4
  bl malloc

  new_cells .req x23
  mov new_cells, x0

  ldr w1, [new_cells, w0,uxtw]
  str w1, [data, w0, uxtw]

  bl free
	ret
	
