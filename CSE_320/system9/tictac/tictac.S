.data
  //
  // The Game description data structure
  //
    .equ    game_rows, 0
    .equ    game_cols, 4
    .equ    game_array, 8
    .equ    game_size, 16
  
  //
  // The Game cell data structure
  // This is the contents of a location in the array
  //
    .equ    cell_expected, 0
    .equ    cell_actual, 4
    .equ    cell_size, 8


.text

.global create_game

//
// Create the game abstract data type
// void *create_game(int rows, int cols)
//
create_game:
	stp x29, x30, [sp, #-16]!
	stp x19, x20, [sp, #-16]!
	stp x21, x22, [sp, #-16]!
  mov w19, w0      // rows
  mov w20, w1      // cols  
 	mov w0,#1
  mov w1, #game_size
  bl calloc       // allocate

  //
  // Set the data structure initial values
  //
  str w19,[x0, #game_rows]
  str w20,[x0, #game_cols]
  mov x21, x0      // game pointer
      
  //
  // Allocate the game array
  //
  mul w0,w19,w20        // row * cols
  mov w1,#cell_size   // Cell size
  bl calloc
                  
  str x0,[x21,#game_array]
                      
  mov x0,x21


create_game_done:
    ldp x21, x22, [sp], #16
    ldp x19, x20, [sp], #16
    ldp x29, x30, [sp], #16
    ret
    
    
.global destroy_game
//
// void destroy_game(void *game)
// Destroy the game, freeing all memory
//
destroy_game:
	stp x29, x30, [sp, #-16]!
  stp x19, x20, [sp, #-16]!
  mov x19, x0
  ldr x0, [x0, #game_array]
  bl free 
  ldp x19, x20, [sp], #16
  ldp x29, x30, [sp], #16
  ret
    
    
.global get_rows

//
// Get the number of rows in the game
// int get_rows(void *game)
//
get_rows:
    //stp x29, x30, [sp, #-16]!
    ldr x0, [x0, #game_rows]
    //ldp x29, x30, [sp], #16
    ret

.global get_cols

//
// Get the number of columns in the game
// int get_cols(void *game)
//
get_cols:
    //stp x29, x30, [sp, #-16]!
    ldr x0, [x0, #game_cols]
    //ldp x29, x30, [sp], #16
    ret

.global display_game

//
// Display the game
//
display_game:
    stp x29, x30, [sp, #-16]!
    mov x21, #0   
    mov x22,#0    
    bl get_rows
    mov x19, x0
    bl get_cols
    mov x20, x0

display:
   cmp x20,x22
   bge rows_display
                                             
   bl set_cell_actual 
   add x22,x22,#1
   b display
rows_display:
    cmp x21,x19
    beq display_game_done
    mov x22, #0
    add x21,x21,#1
    b display

display_game_done:
    ldp x29, x30, [sp], #16
    ret


.global set_cell_actual

//
// int set_cell_actual(void *game, int row, int col, char ch);
// Returns: 1 if the answer value is correct
//
set_cell_actual:
	stp x29, x30, [sp, #-16]!
	stp x19, x20, [sp, #-16]!
  mov w19, w3
  bl game_index
  str w19, [x0, #cell_actual]
  ldr w4, [x0, #cell_expected]
  cmp w19, w4
  bne the_zero 
  mov w0, #1
  //ldp x19, x20, [sp], #16
  //ldp x29, x30, [sp], #16
  //ret
  b set_cell_actual_done  
the_zero:
  mov w0, #0

set_cell_actual_done:
	ldp x19, x20, [sp], #16
	ldp x29, x30, [sp], #16
  ret

.global set_cell_expected

//
// void set_cell_expected(void *game, int row, int col, char ch);
//
set_cell_expected:
	stp x29, x30, [sp, #-16]!
	stp x19, x20, [sp, #-16]!
  mov w19, w3           // save ch in w19
  bl game_index

  str x19, [x0, #cell_expected]  // save ch into game
    
	ldp x19, x20, [sp], #16
	ldp x29, x30, [sp], #16
  ret



.global game_win

//
// int game_win(void *game)
// Returns true when the game is done/won
//
game_win:
    ldr x3, [x0, #game_rows]
    ldr x4, [x0, #game_cols]
    mov w4, w0
rows_game:
   add x5, x5, #1
   cmp x5, x3
   mov x0, #1
   bge game_win_done
   mov x6, #0
cols_game:
   add x6, x6, #1
   cmp x6, x4
   bl game_index
	 //mov w0,#0
    
game_win_done:
    ret
    

.global game_index
//
// int *game_index(void *game, int row, int col)
// Get the address of a row and column in the cells
//   
game_index:
  //stp x29, x30, [sp, #-16]!
  //stp x19, x20, [sp, #-16]!
  ldr w3, [x0, #game_cols]
  ldr x4, [x0, #game_array]

  sub w1, w1, #1
  sub w2, w2, #1

  mov w5, #cell_size
  mul w3, w1, w3
  add w3, w3, w2
  mul w3, w3, w5
  add x0,x4,w3, uxtw

	//mov x0,#0
	ret
	

