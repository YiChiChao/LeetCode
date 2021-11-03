

bool isValid(char * s){
    char stack[10000] = {0};
    int i = 0;
    int ptr = 0;
    while(s[i] != '\0'){
        if(s[i] == '('){
            stack[ptr++] = ')';
        }
        else if(s[i] == '['){
            stack[ptr++] = ']';
        }
        else if(s[i] == '{'){
            stack[ptr++] = '}';
        }
        else{
            if (ptr == 0)return false;
            else if(s[i] != stack[--ptr])return false;
        }
        i++;
    }
    if(ptr != 0)return false;
    return true;
}