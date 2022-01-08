#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> data(10);


	for(int i = 0; i < data.size(); i++)
		cin >> data[i];

	//vector<int>::iterator iter
	for(auto iter = data.begin(); iter != data.end(); iter++)
		cout << *iter << endl;
	return 0;
}

char *strcpy(char *strDest, const char *strSrc){
	if((strDest == NULL) || (strSrc == NULL)){
		return NULL;
	}
	char *strDestCopy = strDest;
	while((*strDest++ = *strDestCopy++) != '\0');
	*strDest = '\0';
	return strDestCopy;
}