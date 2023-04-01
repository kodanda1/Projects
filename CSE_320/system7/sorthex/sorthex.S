.data

msg: .asciz "%d %d\n"

.text

.global sorthex

//
// void sorthex(void *data, int size);
// Sort data into hexadecimal order by 
// half-bytes.
//
sorthex:
    stp x29, x30, [sp, #-16]!
    stp x19, x20, [sp, #-16]!
    stp x21, x22, [sp, #-16]!
    stp x23, x24, [sp, #-16]!
    stp x25, x26, [sp, #-16]!

	//
	// Save off parameters into safe registers
	//
	data .req x19
	mov data, x0
	size .req w20
	mov size, w1

	// Number of hex values
	size2 .req w21
	lsl size2, size, #1
	
	i .req w22	// outer loop counter
	mov i,#0
    
	
outer_loop:
	cmp i, size2
	bgt sorthex_done

	j .req w23	// inner loop counter
	add j, i, #1
    
inner_loop:
	cmp j, size2
	bge outer_loop_end

	mov x0,data
	mov w1,size
	mov w2, i
	bl gethex
	
	aa .req w24
	mov aa, w0
	
	mov x0,data
	mov w1,size
	mov w2, j
	bl gethex
	
	bb .req w25
	mov bb, w0
	
	//
	// Do we need to swap
	//
	cmp aa, bb
	ble after_swap

	mov x0,data
	mov w1,size
	mov w2,i
	mov w3,bb
	bl sethex
	
	mov x0,data
	mov w1,size
	mov w2,j
	mov w3,aa
	bl sethex
 
after_swap:
	add j, j, #1
	b inner_loop
	
outer_loop_end:	
	add i, i, #1
	b outer_loop

sorthex_done:
	ldp x25, x26, [sp], #16
	ldp x23, x24, [sp], #16
	ldp x21, x22, [sp], #16
	ldp x19, x20, [sp], #16
	ldp x29, x30, [sp], #16
	ret
