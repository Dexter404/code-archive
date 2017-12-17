#include<iostream>
#include"string.h"

using namespace std;

main()
{
	String S1("Hello");
	String S2;
	cout<<"String1: "<<S1;

	S2 = "World";
	cout<<"\nString2: "<<S2;

	String S3;
	S3 = (S1 + S2);
	cout<<"\nString3: "<<S3;

	S1 += S2;
	cout<<"\nString1: "<<S1;

	return 0;
}
