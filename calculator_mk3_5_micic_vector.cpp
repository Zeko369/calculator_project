//mk3.5_micic_vector.cpp
//Fran Zekan
//02.06.2017.
/* n1 -> remove ask at start
 * n2 -> rewrite str to arrey for vector
 * n3 -> make todo for vim
 *
 *
 *
*/

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//remove ask at beg
//<:1>
bool debug = 1;

//string user = "\033[1;32mzeko\033[0m";
//string root = "\033[1;31mroot\033[0m";
//string rest = "\033[1;36m@calculator:~$ \033[0m";

//for non termianl
string user = "";
string root = "";
string rest = "";

//main
string a;		//in
string b;		//string with in but beautiful
float x;		//out

int highestStep = 0;    //1(+-), 2(*/), 3(()), 4(^sqrt) 

//const max for nums and ops
const int lenNums = 10;
const int lenOps = 10;
int n_nums, n_ops;

vector<float> num(lenNums);
vector<char> ops(lenOps);

int nIter = 0;					//current number
int oIter = 0;					//        operator
double tempAdd = 0;				//beg from string to vector

//FUNCTIONS
bool isNum(char testNum){ return testNum - 48 >= 0 && testNum - 48 < 10 ? 1 : 0; }
void printB(), printNum(), printOps();
void clear();
int addDot(int from); int addNum(int from);

float primary(int beg, int end){}
float secondry(int beg, int end){}

/////////////////////////// MAIN //////////////////////////////////////////////////////
int main()
{
	// cout << "\033[1;31mbold red text\033[0m\n";
	string debugOnOff;

	cout << "Calculator, new from scrach MK2 \n";
	cout << "Debug ?: ";
	getline(cin, debugOnOff);

	if(debugOnOff == ""){ debug = 1; }
	else{ debug = 0; }
	
	while(1)
	{
		cout << user << rest;
		clear();
		getline(cin, a);
		if(a == "quit" || a == "exit"){ break; }

	    if(debug)
		{
			for(int i = 0; i<a.size(); i++){ cout << a[i]; }
			cout << endl;
		}	
		
		for(int i = 0; i<a.size(); i++)
		{
			if(a[i] == ' '){ continue; }			//space
			else if(isNum(a[i] || a[i] == '.'))		//num
			{
							
			}
			else
			{
				b += a[i];
				
				ops.push_back(a[i]);
				oIter++;
				n_ops++;
				
				if((a[i] == '+' || a[i] == '-') && highestStep == 0){ highestStep = 1; }
				else if((a[i] == '*' || a[i] == '/') && highestStep < 2){ highestStep = 2; }
				else if((a[i] == '(') && highestStep < 3){ highestStep = 3; }
				else{ highestStep = 4; }
			}		
		}
		
		if(debug)
		{
			printB();
			printNum();
			printOps();

			cout << "Level: " << highestStep << endl;
		}	
		
		cout << root << rest <<  x << endl;
	}
	
	return 0;
}

void clear()
{
	a = "";
	b = "";
	oIter = 0; nIter = 0;
	n_ops = 0; n_nums = 0;
	highestStep = 0;

	for(int i = 0; i<num.size(); i++){ num[i] = 0; }
	for(int i = 0; i<ops.size(); i++){ ops[i] = 0; }
}

void printB()
{
	cout << "B: ";
	for(int i = 0; i<b.size(); i++)
	{
		cout << b[i];
	}
	cout << endl;
}

void printNum()
{
	cout << "nums: ";
	for(int i = 0; i<n_nums-1; i++)
	{
		cout << num[i] << ", ";
	}
	cout << num[n_nums-1] << "\n";
}

void printOps()
{
	cout << "ops: ";
	for(int i = 0; i<n_ops-1; i++)
	{
		cout << ops[i] << ", ";
	}
	cout << ops[n_ops-1] << "\n";
}

/*	//<:2>
			else if(isNum(a[i]) || a[i] == '.')		   //num
			{ 
				while(isNum(a[i]))
				{
					num[nIter] += a[i] - 48;
					num[nIter] *= 10;
					b += a[i];
					i++;
				}

				num[nIter] /= 10;
				
				if(a[i] == '.')
				{
					b += '.';

					if(!(isNum(a[i-1])))
					{
						num[nIter] = 0;
					}

					i++;
					rem = 0;

					while(isNum(a[i]))
					{
						rem += a[i] - 48;
						rem *= 10;
						b += a[i];
						i++;
					}

				        rem /= 10;

					while(rem > 1){ rem /= 10.0; }

					num[nIter] += rem;
				}

	                        nIter++;
				n_nums++;
*/
