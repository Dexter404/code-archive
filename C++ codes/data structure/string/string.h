#ifndef STRING_H
#define STRING_H
#include<iostream>
using namespace std;
class String {
	char *str;
public:
	String() {
		str = new char[1];
		str[0] = '\0';
	}
	String(char arr[]) {
		int len;
		for(len=0; arr[len]!='\0'; len++);
		str = new char[len+1];
		for(int i=0; i<len; i++)
			str[i] = arr[i];
		str[len]='\0';
	}	
	String(String &S) {
		int len;
		for(len=0; S.str[len]!='\0'; len++);
		str = new char[len+1];
		for(int i=0; i<len; i++)
			str[i] = S.str[i];
		str[len]='\0';		
	}
	~String() {
		delete [] str;
	}
	
	char operator[](int index) { return str[index]; }
	const char operator[](int index) const { return str[index]; }
	
	const String& operator=(const String &S) {
		delete [] str;
		str = new char[S.length()+1];
		for(int i=0; i<S.length(); i++)
			str[i] = S.str[i];
		str[S.length()]='\0';		
		return S;
	}
	const char* operator=(const char *ch) {
		delete [] str;
		int len;
		for(len=0; ch[len]!='\0'; len++);
		
		str = new char[len+1];
		for(int i=0; i<len; i++)
			str[i] = ch[i];
		str[len]='\0';
		
		return ch;
	}
	String operator+(const String &S) {
		String result;
		delete [] result.str;
		result.str = new char[length() + S.length() + 1];
		
		int i;
		for(i=0; i<length(); i++)
			result.str[i] = str[i];
		for(i=0; i<S.length(); i++)
			result.str[length() + i] = S.str[i];			
		result.str[length() + i] = '\0';
		
		return result;
	}
	String& operator+=(const String &S) {
		String temp(this->str);
		
		delete [] str;
		str = new char[temp.length() + S.length() + 1];
		
		int i;
		for(i=0; i<temp.length(); i++)
			str[i] = temp.str[i];
		for(i=0; i<S.length(); i++)
			str[temp.length() + i] = S.str[i];			
		str[temp.length() + i] = '\0';
		
		return *this;
	}

	int length() const {
		int len;
		for(len=0; str[len]!='\0'; len++);
		return len;
	}
	
	friend ostream& operator<<(ostream& ,const String );
};
ostream& operator<<(ostream& out, const String S) {
	for(int i=0; S.str[i]!='\0'; i++)
		out<<S.str[i];
	return out;
}
#endif
