
#include <iostream>
#include <string>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
int main() {
	std::string str;
	do {
		char *s,*e;
		stack<char> stack;
		std::cin>>str;	
		if(std::cin.fail()) break;
		cout<<"Input :"<<str<<endl;
		s= &str[0];
		e = &str[str.length()-1];
		while( e > s) {
			while((*s++ == *e--) && (s != e));
			if(s < e) {
				cout << *(s-1) << *(e+1)<<endl;
				stack.push(*(s-1));
			}	
					
		 

		}



	}while(1);

}
