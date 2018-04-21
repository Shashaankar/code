#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>


/** Write a function “runCustomerSimulation” that takes following two
 * inputs
 * a) An integer ‘n': total number of computers in a cafe and a string:
 * b) A sequence of uppercase letters ‘seq': Letters in the sequence
 * occur in pairs. The first occurrence indicates the arrival of a
 * customer; the second indicates the departure of that same customer.
 *
 * A customer will be serviced if there is an unoccupied computer. No
 * letter will occur more than two times.
 * Customers who leave without using a computer always depart before
 * customers who are currently using the computers. There are at most 20
 * computers per cafe.
 *
 * For each set of input the function should output a number telling how
 * many customers, if any walked away without using a computer. Return 0
 * if all the customers were able to use a computer.
 *
 * runCustomerSimulation (2, “ABBAJJKZKZ”) should return 0
 *
 * runCustomerSimulation (3, “GACCBDDBAGEE”) should return 1 as ‘D’ was
 * not able to get any computer
 *
 * runCustomerSimulation (3, “GACCBGDDBAEE”) should return 0
 *
 * runCustomerSimulation (1, “ABCBCA”) should return 2 as ‘B’ and ‘C’
 * were not able to get any computer.
 *
 * runCustomerSimulation(1, “ABCBCADEED”) should return 3 as ‘B’, ‘C’
 * and ‘E’ were not able to get any computer.
 */


/** 
 * Solution: 
 * # Let number of computers be N
 * # str be the sequence of customers coming and leving the coffee shop
 * # Initialize a count array of number of alphabets or 255
 * # Traverse through the string, and increment count in count array for
 * every char scanned in the string. Now decrememnt the available
 * computers N for the first char scanned.
 * # from next character, first check if he's a new or leaving customer
 * with the value in count array. Based on that decrement or increment
 * the value N.
 * # At any point if we see a char with no computers available then inc
 * result.
 * # Loop until all chars are scanned.
 */


void main() {








} 
