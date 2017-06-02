<<<<<<< HEAD
//new_from_scratch_mk2.cpp
//Fran Zekan
//21.05.2017.
/* Remove iters
 *  
 *
 *
 *
*/

#include <iostream>

using namespace std;

bool debug = 1;
string user = "\033[1;32mzeko\033[0m";
string root = "\033[1;31mroot\033[0m";
string rest = "\033[1;36m@calculator:~$ \033[0m";

string a;		//in
string b;

const int lenNums = 10;
const int lenOps = 10;
float num[lenNums] = {};
float rem = 0.0;
char ops[lenOps] = {};
int n_nums, n_ops;

int nIter = 0;
int oIter = 0;

float x;		//out

int highestStep = 0;    //1(+-), 2(*/), 3(()), 4(^sqrt) 

bool isNum(char testNum){ return testNum - 48 >= 0 && testNum - 48 < 10 ? 1 : 0; }
void printB(), printNum(), printOps();
void clear();

float primary(int beg, int end); float secondry(int beg, int end);

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
			if(a[i] == ' '){ continue; }       //spaec
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
			}
		        else				   //op
			{
				b += a[i];

				ops[oIter] = a[i];
				oIter++;
				n_ops++;

				if((a[i] == '+' || a[i] == '-') && highestStep == 0){ highestStep = 1; }
				else if((a[i] == '*' || a[i] == '/') && highestStep < 2){ highestStep = 2; }
				else if((a[i] == '(') && highestStep < 3){ highestStep = 3; }
			}
		}

		if(debug)
		{
			printB();
			printNum();
			printOps();

			cout << "Level: " << highestStep << endl;
		}

		if(highestStep == 1)	     // + and -
		{
			x = primary(0, b.size());	
		}
		else if(highestStep == 2)    // * and /
		{
			x = secondry(0, b.size());	
		}
		else if(highestStep == 3)    // ( and )
		{}
		else if(highestStep == 4)    // ^ and sqrt
		{}
		else{ cout << "Go home you're drunk\n"; break; }

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
	rem = 0.0;

	for(int i = 0; i<lenNums; i++)
	{
		num[i] = 0;
		ops[i] = 0;
	}
}

float primary(int beg, int end)
{
	float temp;
	temp = num[beg];

	for(int i = beg; i<end; i++)
	{
		if(ops[i] == '+'){ temp += num[i+1]; }
		else if(ops[i] == '-'){ temp -= num[i+1]; }
	}	

	return temp;
}

float secondry(int beg, int end)
{
	for(int i = beg; i<end; i++)
	{
		//1+2*4
		if(ops[i] == '*')
		{
			num[i+1] *= num[i];
			num[i] = 0;
			ops[i] = '+';
		}
		else if(ops[i] == '/')
		{
			num[i+1] = num[i] / num[i+1];
			num[i] = 0;
			ops[i] = '+';
		}
	}

	return primary(beg, end);
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
=======
		for(int i = 0; i<a.size(); i++)
		{
			if(a[i] == ' '){ continue; }       //spaec
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
			}
		        else				   //op
			{
				b += a[i];

				ops[oIter] = a[i];
				oIter++;
				n_ops++;

				if((a[i] == '+' || a[i] == '-') && highestStep == 0){ highestStep = 1; }
				else if((a[i] == '*' || a[i] == '/') && highestStep < 2){ highestStep = 2; }
				else if((a[i] == '(') && highestStep < 3){ highestStep = 3; }
			}
		}
>>>>>>> b4bd8c65817e2c920c3a2fd08fdec3db1c2d0a02
