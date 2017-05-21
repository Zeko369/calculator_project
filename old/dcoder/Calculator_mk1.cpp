#include <iostream>

using namespace std;

string a;
double x;

const int numbers_len = 10;
const int ops_len = 10;

float numbers[numbers_len] = {};
float float_reminder[numbers_len] = {};
int iter = 0;
int n_numbers = 0;

float ten = 10;

char ops[ops_len] = {};
int opsIter = 0;
int n_ops = 0;

int highestStep = 0; //1(+-), 2(*/), 3(()), 4(^)

void printNumbres()
{
	cout << "/////////////////////////////" << endl;

	for(int i = 0; i<n_numbers; i++)
	{
		cout << numbers[i] << " ";
	}

	cout << endl;
}

void printRemains()
{
	cout << "/////////////////////////////" << endl;

	for(int i = 0; i<n_numbers; i++)
	{
		cout << float_reminder[i] << " ";
	}

	cout << endl;
}

void printOps()
{
	for(int i = 0; i<n_ops; i++)
	{
		cout << ops[i] << " ";
	}

	cout << endl;
}

double primary(int beg1, int end1, int offset1)
{
	double e;
	for(int i = beg1; i<end1; i++)
	{
		if(i == 0){ e = numbers[i]; }
		else
		{
			if(ops[i-1 + offset1] == '+'){ e += numbers[i];}
			else if(ops[i-1 + offset1] == '-'){ e -= numbers[i];}
			// else{ cout << "FUCK, primary (,"; }

		   // cout << "h8" << ops[i - 1 + offset1] << endl;
          // printNumbres();
		}
	}

	return e;
}

double secondary(int beg, int end, int offset)
{
	for(int i = beg; i<end; i++)	
	{
		if(ops[i+offset] == '*')
		{
			numbers[i+1] *= numbers[i];
			numbers[i] = 0;
			ops[i+offset] = '+';
		}
		else if(ops[i+offset] == '/')
		{
			numbers[i+1] = numbers[i] / numbers[i+1];
			numbers[i] = 0;
			ops[i+offset] = '+';
		}
		// else cout << "Derp /secondary,";
	}

	return primary(beg, end, offset);
}

int main(int argc, char const* argv[])
{
	getline(cin, a);

	for(int i = 0; i<a.size(); i++){ cout << a[i]; }
	cout << endl;

	for(int i = 0; i<a.size(); i++)
	{
		if((a[i] - 48 >= 0 && a[i] - 48 < 10)  || a[i] == '.')
		{	
			if(a[i] == '.')
			{
				//only .5 for 0.5
				if(!(a[i] - 48 >= 0 && a[i] - 48 < 10))
				{
					//cout << "only .5 format\n";
					numbers[iter] = 0;
					iter++;
					n_numbers++;
				}
				
				i++;
				
				while(a[i] - 48 >= 0 && a[i] - 48 < 10)
				{
					float_reminder[iter-1] += a[i] - 48;
					i++;
				}
				
				//cout << numbers[iter-1] << " " << float_reminder[iter-1] << endl;
			}
			else
			{
				numbers[iter] += a[i] - 48;
				if(a[i+1] - 48 >= 0 && a[i+1] - 48 < 10){ numbers[iter] *= 10; }
				else{ iter++; n_numbers++; }	
			}
		}
		else if(a[i] == ' ') {}
		else
		{
			ops[opsIter] = a[i];
			opsIter++; n_ops++;

			if((a[i] == '+' || a[i] == '-') && highestStep == 0){ highestStep = 1; }
			if((a[i] == '*' || a[i] == '/') && (highestStep == 1 || highestStep == 0)){ highestStep = 2; }
			if((a[i] == '(')){ highestStep = 3; }
		}
	}

	// printOps();
	
	//printNumbres();
	//printRemains();
	
	for(int i = 0; i<n_numbers; i++)
	{
		while(float_reminder[i] > 1){ float_reminder[i] /= ten; }
		numbers[i] += float_reminder[i];
	}
 
	if(highestStep == 1)
	{
		x = primary(0, n_numbers, 0);
	}
	else if(highestStep == 2)
	{
		x = secondary(0, n_numbers, 0);
	}
	else if(highestStep == 3)
	{
		cout << "Fuck not done yet" << endl;	
	}
	
	cout << x << endl;
	
	return 0;
}