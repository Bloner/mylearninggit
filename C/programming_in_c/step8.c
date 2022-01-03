//Arrays
#include <stdio.h>
#define NumMovies 10
#define MaxGrosses 5
#define MaxWord 20

int main(){
	char c;
	char str[MaxWord+1];
	char lstr[MaxWord+1];
	int llen = 0;
	int len = 0;
	int totallen = 0;
	int wn = 0;
	puts("Enter text. Include a dot ('.') to end a sentence to exit:");
	do{
		c = getchar();
		if(c != ' ' && c != '.'){
			if(len < MaxWord){
				str[len] = c;
				len++;
			}
		}
		else if(len != 0){
			if(len > llen){
				llen = len;
				int j;
				for(j = 0;j<len;j++)
					lstr[j] = str[j];
				lstr[++j] = 0;
			}
			totallen += len;
			wn ++;
			str[len] = 0;
			//printf("%s\n", str);
			len = 0;
		}
	}
	while(c != '.');
	printf("The average word length: %.1lf\n", (double)totallen/(double)wn);
	printf("The longest word: %s", lstr);
	#if 0	
	double gross[NumMovies] = {4633070, 3856195, 3171189, 1877685, 3251622,
                               3156594, 1629735, 2659234, 2028036, 510768};
	char *names[NumMovies] = {"Hall Pass", "Unknown", "I Am Number Four", "The King's Speech", "Just Go With It", "Gnomeo and Juliet", "Drive Angry", "Justin Beiber: Never Say Never", "Big Mommas: Like Father, Like Son", "True Grit"};
	int i,j;
	for(i = 0; i < NumMovies; i++)
		printf("Movie %2d %33s: %.0f\n", i+1, names[i], gross[i]);
	int highestGrossIndex = 0;
    double highestGross = 0;
	for(i=0;  i<NumMovies;  i++)
    {
        if(gross[i] > highestGross)
        {
            highestGrossIndex = i;
            highestGross = gross[highestGrossIndex];
        }
    }
    printf("The highest grossing film is: %s\n", names[highestGrossIndex]);
	double maxGross[MaxGrosses] = {500000, 1000000, 2000000, 4000000, 10000000};
	for(j = 0; j<MaxGrosses; j++){
		highestGrossIndex = 0;
		highestGross = 0;
		for(i=0;  i<NumMovies;  i++)
		{
			if(gross[i] > highestGross && gross[i] < maxGross[j])
			{
				highestGrossIndex = i;
				highestGross = gross[highestGrossIndex];
			}
		}
		if(highestGross == 0)
			printf("No film made less than %.0lf\n", maxGross[j]);
		else
			printf("The highest grossing less than %.0lf is %.0lf at %s\n", maxGross[j], highestGross, names[highestGrossIndex]);
	}
	#endif
	return 0;
}
