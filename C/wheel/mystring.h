int strlen(char *s){
	int i = 0;
	while(*s++ != '\0')
		i++;
	return i;
}

int strcmp(char *s, char *t){
	while(*s == *t){
		if(*s == '\0' && *t == '\0')
			return 1;
	}
	return -1;
}
/*
strcat(s, t)
strncat(s, t, n)
strcmp(s, t)
strncmp(s, t, n)
strcpy(s, t)
strncpy(s, t, n)
strlen(s)
*/

//atoi
