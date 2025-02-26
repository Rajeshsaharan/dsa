char* findValidPair(char* s) {
    int size = strlen(s);
    int arr[10] = {0}; // array for counting frequency becasue all we have s
                       // consist only by '1' to '9';
    int i = 0;
    // first we run loop for counting frequency
    while (i < size) {
        int value = s[i] - '0';
        arr[value] += 1;
        i++;
    }
    // now we have all frequency of every item in array
    i = 0;
    bool break_flag = false;
    while (i < size - 1) {
        int first_value = s[i] - '0';
        int second_value = s[i + 1] - '0';
        if (arr[first_value] == first_value &&
            arr[second_value] == second_value && first_value != second_value) {
            break_flag = true;
            break;
        }
        i++;
    }

    char* string = (char*)malloc(3 * sizeof(char));
    if (break_flag) {
        string[0] = s[i];
        string[1] = s[i + 1];
        string[2] = '\0';
    }else{
        string[0] = '\0';
    }

    return string;
}