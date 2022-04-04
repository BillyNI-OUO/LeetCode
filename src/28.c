//Implement strStr()

int* Failure(char *needle, int len){
	int *KMPtable;
	KMPtable = (int *)malloc(sizeof(int)*len);
	KMPtable[0] = 0;
	int i = 1;
	int prev = 0;

	for(int i = 1; i < len; i ++){
		prev = KMPtable[i-1];
		while(needle[i] != needle[prev]){
			if(prev == 0){
				KMPtable[i] = 0;
				break;
			}else{
				prev = KMPtable[prev-1];
			}
		}
		if(needle[i] == needle[prev]){
			KMPtable[i] = prev + 1;
		}else{
            
        }
	}

	return KMPtable;
}

int strStr(char * haystack, char * needle){
	int nlen = 0;
	while(1){
		if(needle[++nlen] == '\0')
			break;
	}
    
	int *KMPtable = Failure(needle, nlen);

	int hlen = 0;
	while(1){
		if(haystack[++hlen] == '\0')
			break;
	}

	int KMPposition = 0;
	int i = 0;
	while(i < hlen){
		if(haystack[i] == needle[KMPposition]){
			i++;
			KMPposition++;
			if(KMPposition == nlen)return i-nlen;
		}else {
			if(KMPposition == 0){
				i++;
			}else{
				KMPposition = KMPtable[KMPposition-1];
			}
		}
	}

	return -1;
}

