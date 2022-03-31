char * longestPalindrome(char * s){
	int **array;
	int max, max_x;
	max = 1;
	max_x = 0;
	int n = strlen(s);
	if(n == 0)return NULL;
	if(n == 1)return s;
	array = (int **)calloc(n, sizeof(int *));
	for(int i =  0; i < n; i ++){
		array[i] = (int *)calloc(n, sizeof(int));
	}

	for(int i = 0; i < n; i ++){
		array[i][i] = 1;

		if(i < n-1)
			if(s[i] == s[i+1]){
				array[i][i+1] = 2;
				max = 2;
				max_x = i;
			}
	}
	for(int i = 2; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(i + j > n)continue;
			if(array[j + 1][i + j - 1] == i-1 && s[j] == s[j+i]){
				array[j][i] = i + 1;
				if(max < i + 1){
					max = i + 1;
					max_x = j;
				}
			}
		}
	}
	char *ans;
	ans = (char *)malloc(sizeof(char)*(max+1));
	for(int i = 0; i < max; i ++){
		ans[i] = s[max_x + i];
	}
	ans[max] = '\0';
	return ans;


}