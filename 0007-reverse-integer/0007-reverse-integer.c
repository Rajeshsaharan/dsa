#define min -2147483648 
#define max 2147483647

int abs(int x){
    if( x < 0) return -x;
    return x;
}

int power_int(int base, int power) {
    if (power == 0) return 1;

    int i = 0;
    int value = 1;

    while (i < power) {
        if (base != 0 && value > INT_MAX / base) {
            // Overflow would happen
            return -1;
        }
        value *= base;
        i++;
    }

    return value;
}



void reverse_helper(int x,int * result, int * count){
    
    if(x >= 0 && x < 10 || x < 0 && x > -10){
        result[*count] = abs(x);
        return;
    }
    int val = x %10;
    result[*count] = abs(val);
    x = x / 10;
    *count = (*count) + 1;
    reverse_helper(x,result, count);
}



int reverse(int x){
    int result[10];
    int count = 0;
    reverse_helper(x, result, &count);
    int i = 0;
    int power = count;
    int total = 0;
    while(i <= count){
        int val = power_int(10, power);
        if (val == -1) return 0;
        if(result[i] > INT_MAX/val){
            return 0;
        }
        if(total > INT_MAX - result[i] * val){
            return 0;
        }
         total += result[i] * val;
         i++;
         power--;
    }
   if(x < 0){
    return -total;
   }else{
    return total;
   }
}