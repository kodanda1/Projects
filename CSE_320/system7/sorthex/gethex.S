
.text

.global gethex

//
// int gethex(void *data, int size, int index);
// Get's a 4 bit value, where index is assumed
// to be an index to hex values in a string of 
// data bytes. index=0 is the first 4 bits (most 
// significant) and index=1 is the next 4 bits
// (least significant)
//
gethex:
    stp x29, x30, [sp, #-16]!
    stp x19, x20, [sp, #-16]!
    stp x21, x22, [sp, #-16]!

    //
    // Save off parameters into safe registers
    //
    data .req x19
    mov data, x0
    size .req w20
    mov size, w1
    index .req w21
    mov index, w2
    cmp index, #0
    bmi get_hex_zero
    
    // Compute the byte 
    byte .req w22
    lsr byte, index, #1    // index/2

    //Ensure we are in range
    cmp byte, size
    bge get_hex_zero
    
    // Load the byte
    ldrb w0,[data, byte, uxtw]
    
    // High or low?
    tst index,#1
    bne get_hex_low
    
    // Get high part
    lsr w0, w0,#4    
    b get_hex_done
    
get_hex_low:
    and w0,w0,#0xf
    b get_hex_done
    
get_hex_zero:
    mov w0,#0

get_hex_done:
	ldp x21, x22, [sp], #16
	ldp x19, x20, [sp], #16
	ldp x29, x30, [sp], #16
	ret
