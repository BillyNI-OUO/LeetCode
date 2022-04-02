//Valid Palindrome II
bool validPalindromeSmall(char *s, int left, int right){
	while(left < right){
		if(s[left++] != s[right--])return false;
	} 
	return true;
}

bool validPalindrome(char * s){
	int len = 0;
	while(1){
		if(s[++len] == '\0')break;
	}
    int left = 0, right = len-1;


    while(left < right){
    	if(s[left] == s[right]){
    		left ++;
    		right --;
    	}
    	else{
    		return validPalindromeSmall(s, left+1, right) || validPalindromeSmall(s, left, right-1);

    	}
    }

	return true;
}