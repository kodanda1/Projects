
.text

.global sethex

//
// int sethex(data, size, index, value)
// Set's a 4 bit value, where index is assumed
// to be an index to hex values in a string of 
// data bytes. index=0 is the first 4 bits (most 
// significant) and index=1 is the next 4 bits
// (least significant)
//
sethex:
    stp x29, x30, [sp, #-16]!
    stp x19, x20, [sp, #-16]!
    stp x21, x22, [sp, #-16]!
    stp x23, x24, [sp, #-16]!
	
	//
	// Save off parameters into safe registers
	//
	data .req x19
	mov data, x0
	size .req w20
	mov size, w1
	index .req w21
	mov index, w2
	value .req w22
	and value,w3,#0xf		// Just to be sure!
	
	// Compute the byte 
	byte .req w23
	lsr byte, index, #1	// index/2
    
	// Ensure index is valid
	cmp byte, size
	bge set_hex_done
	
	// Load the byte
	ldrb w0,[data, byte, uxtw]
	
	// High or low?
	tst index,#1
	bne set_hex_low
	
	// Set high part
	and w0,w0,#0xf
  lsl value, value, #4
	orr w0,w0,value
	strb w0,[data, byte, uxtw]
	b set_hex_done
	
set_hex_low:
	and w0,w0,#0xf0
	orr w0,w0,value
	strb w0,[data, byte, uxtw]
	b set_hex_done
	
set_hex_done:
	ldp x23, x24, [sp], #16
	ldp x21, x22, [sp], #16
	ldp x19, x20, [sp], #16
	ldp x29, x30, [sp], #16
	ret
