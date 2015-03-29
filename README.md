# ECE429_Project1

## Instructions

1. Transform the C program P1 into another C program P2. The program P2 should contain variables with names of the form TMP1, TMP2, TMP3, etc.; additionally, it should contain labels. The program P2 may only contain instructions of the form:
  1. "A = B op C" where A, B, C are simple variables or constants and "op" is +, -, *, etc. (Signifying ADD, SUB, MULT, etc.)
  2. "if(A op B)" where A, B are simple variables or constants and "op" is ==, >, >=, etc. (Signifying COMPARE)
  3. "goto Label" (Signifying JUMP)
  4. "A = B" where A is a simple variable and B is an array variable or A is an array variable and B is a simple variable (Signifying LOAD and STORE, respectively)
  5. "scanf()" or "printf()" with only one argument (Signifying LOAD and STORE, respectively)
2. Introduce instrumentation code into program P2 to count the number of executions ICi of each type of instruction i, as well as the total number IC of all executed instructions. (Note that LOAD and STORE correpsond to two C forms as given above).
3. Execute program P2 for input values of d = 4, 6, 7 and print out an analytical summary with the ICi and ICi/IC values for each instruction under each input case.
