
/**
Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str 
is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, 
INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

*/

// TODO: few test cases are failing

int myAtoi(char* str) {
    int i,j,minus_flag,max_int, min_int,sum,val,junk_flag,num_start_flag,plus_flag;
    char *num_str = NULL;
    
    max_int = (1<<31) -1;
    min_int = (1<<31);
    
    printf("max_int = %d, min_int = %d\n", max_int, min_int);
    if (!str) {
        return NULL;
    }
    i = j = 0;
    junk_flag = num_start_flag = 0;
    minus_flag = 0;
    plus_flag = 0;
    
    val = 0;
    sum = 0;
    while (str[i]) {
        
        if (str[i] == '-') {
            i++;
            if (num_start_flag || minus_flag || plus_flag) {
                goto cal_num;
            }
            minus_flag = 1;
            continue;
        }
        
        if (str[i] == '+') {
            i++;
            if (num_start_flag || minus_flag || plus_flag) {
                goto cal_num;
            }
            plus_flag = 1;
            continue;
        }
        
        // Ignore white spaces at the begining
        if (str[i] == ' ') {
            i++;
            // If white spaces in between the number, ignore rest of the chars
            if (num_start_flag || plus_flag || minus_flag) {
                goto cal_num;
            }
            continue;
        }
        
        // Ignore all other Junk chars
        if (((int)str[i] < (int)'0') || ((int)str[i] > (int)'9')) {
            i++;
            junk_flag = 1;
        } else {
            // Valid numeric values
            val = (str[i] - '0');
        
            // Handle overflow condition
            if ((sum != 0) && (max_int/sum < 9) && (max_int/sum > -9)) {
                
                if (minus_flag) {
                 return min_int;   
                }
            
                return max_int;
            }
            sum = (sum * 10) + val;
            printf ("\n val = %d, sum = %d", val, sum);
            i++;
            j++;
            num_start_flag = 1;
        }
        
        if (junk_flag) {
            goto cal_num;
        }
    }
    
cal_num:
    
    if (minus_flag) {
        return -sum;
    } else {
        if (sum < 0) {
            return max_int;
        }
    }
    return sum;
    
}


