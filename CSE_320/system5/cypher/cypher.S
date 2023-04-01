
.text

.global cypher

/*
 * Compute the length of a  string
 * x0 - Address of the string in memory
 * x1 - Address of a substitution cypher in memory
 */
cypher:
   ldrsb w2, [x0]   // Get character from the string
   cmp w2, #0      // Null terminator?
   beq done        // If so
               
   // Ensure the character is not negative
   bmi skip
                   
  // x0 - Address in string
  // x1 - Address of the cypher
  // w2 - Character from the string
  // x3 - Computed address in the cypher
  // w4 - Cyphered character
                  
  // Compute addrss in the cypher
  add x3, x1, w2, uxtw
  ldrb w4, [x3]   // Get the byte
  strb w4, [x0]   // Store it
                               
skip:
    add x0, x0, #1  // Increment the address
    b cypher
done:
    ret             // return
