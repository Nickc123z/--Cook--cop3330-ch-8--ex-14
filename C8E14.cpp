/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Nick Cook
 */

#include<vector>
#include <iostream>
using namespace std;


vector<int> get_sizeof(const vector<string>& vs)
{
    int i = 0;
	vector<int> result(vs.size());

	for (i =0; i<vs.size(); ++i)
		result[i] = vs[i].size();



	return result;
}


int long1(const vector<string>& v)
{
    int i = 0;
    int m1 = v[0].size();		
	int max = 0;
	
	for (i=0; i<v.size(); ++i)
		if (m1<v[i].size()) {
			max = i;
			m1 = v[i].size();
		}


	return max;
}

string& short1(vector<string>& v)
{
    int i = 0;
    int m2 = v[0].size();	
	int min = 0;
	
	for (i=0; i<v.size(); ++i)
		if (v[i].size()<m2) {
			min = i;
			m2 = v[i].size();
		}
	return v[min];
}



string lex1(const vector<string>& v)
{
    int i = 0;
    int first_index = 0;


	for (i=0; i<v.size(); ++i)
		if (v[i]<v[first_index])
			first_index = i;
	return v[first_index];
}


void lex2(vector<string>& v, int& last)
{

	int last_index = 0;
	for (int i=0; i<v.size(); ++i)
		if (v[last_index]<v[i]) 
			last_index = i;
	last = last_index;	
}


int main()
{

	vector<string> vs;



	vs.push_back("catcatcatcatcatcat");
	vs.push_back("k");
	vs.push_back("K");
	vs.push_back("dogdogdogdogdog");	
	vs.push_back("Dogdogdogdogdog");	
	vs.push_back("Catcatcatcatcatcat");	
	vs.push_back("?");	

	cout << "sizes: ";
	vector<int> lengths = get_sizeof(vs);
    
	for (int i =0; i<lengths.size(); i++) 
    cout << lengths[i] << ' ';
	cout << '\n';

	int i = long1(vs);
	cout << ":" << i << "; string=='" << vs[i] << "'\n";	
	cout << " '" << short1(vs) << "'\n";	

	cout << " '" << lex1(vs) << "'\n";
	
	lex2(vs,i);
	cout << "index==" << i << "; string=='" << vs[i] << "'\n";
}