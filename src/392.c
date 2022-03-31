bool isSubsequence(char * s, char * t){
	int sSize = strlen(s);
	int tSize = strlen(t);

	int *table = malloc(sizeof(int)*sSize*tSize);
	for(int i = 0; i < sSize*tSize; i ++)
		table[i] = 0;
	for(int i = 0; i < sSize; i ++){
		for(int j = 0; j < tSize; j ++){
			
			if(s[i] == t[j]){
				if(i * j > 0)
					table[tSize*i+j] = table[tSize*(i-1)+j-1];
				table[tSize*i+j] += 1; 
			}
			else{
				int up, left = 0;
				if(i > 0)up = table[tSize*(i-1)+j];
				if(j > 0)left = table[tSize*i+j-1];
				table[tSize*i+j] = up > left ? up : left;
			}
		}
	}
	if(table[tSize*sSize-1] == sSize)return true;
	return false;
}