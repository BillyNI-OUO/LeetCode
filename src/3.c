int lengthOfLongestSubstring(char * s){
	char cur;
	int* index;
	int length = strlen(s);
	index = (int*)malloc(sizeof(int)*strlen(s)); 
	for(int i = 0;i < length; i ++){
		index[i] = 1;
	}
	for(int i = 1; i < length; i ++){
		int size = index[i-1];
		for(int j = 0; j < size; j ++){
			if(s[i-size+j] == s[i])index[i] += size-j-1;
		}
	}
	int max = 0;
	int max_i = 0;
	for(int = 0; i < length; i ++){
		if(max < index[i]){
			max = index[i];
			max_i = i;
		}
	}
	return max;
}