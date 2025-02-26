



int firstUniqChar(char* s) {
    int array[26] = {0};
    int i = 0;
    while (s[i] != '\0') {
        int value = s[i] - 'a';
        array[value] += 1;
        i++;
    }
    i = 0;
    while(i < 26){
        printf("for every char %c -> %d\n", i + 97, array[i]);
        i++;
    }


    i =0;
    while (s[i] != '\0') {
        int value = s[i] - 'a';
        
        if (array[value] == 1) {
            return i;
        }

        i++;
    }
    return -1;
}