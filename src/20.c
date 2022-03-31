bool isLeft(char s){
    if(s == '{')return true;
    if(s == '(')return true;
    if(s == '[')return true;
    return false;
}
bool check(char left, char right){
    if(left == '(' && right == ')')return true;
    if(left == '{' && right == '}')return true;
    if(left == '[' && right == ']')return true;

    return false;
}
bool isValid(char * s){
    char stack[10001];
    int index = -1;
    int length = strlen(s);
    for(int i = 0; i < length; i ++){
        if(isLeft(s[i])){
            index++;
            stack[index] = s[i];
        }
        else{
            if(index < 0)return false;
            char left = stack[index--];
            if(!check(left, s[i]))return false;
        }
    }
    return index < 0;


}