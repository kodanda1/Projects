/*
 * Functions to determine first and last minor 
 * boarding a cruise ship.
 */
 
.text
.global first_minor
.global last_minor


/*
 * Determine the first minor (<18) in an array of numbers
 * x0 - Pointer to the array
 * x1 - Number of items in the array
 */
first_minor:
    mov x0,#0
    ret             // return
    

/*
 * Determine the last minor (<18) in an array of numbers
 * x0 - Pointer to the array
 * x1 - Number of items in the array
 */
last_minor:
    mov x0,#0
    ret             // return
