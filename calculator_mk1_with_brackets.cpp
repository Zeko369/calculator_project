#include <iostream>

using namespace std;

string a;
string b; // nicer way of doing a
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
int bracketCount = 0;

int highestStep = 0; //1(+-), 2(*/), 3(()), 4(^)

void printB()
{
    for(int i = 0; i<b.size(); i++)
    {
        cout << b[i];
    }
    
    cout << endl;
}

void printNumbres()
{
	cout << "/////////////////////////////" << endl;

	for(int i = 0; i<n_numbers-1; i++)
	{
		cout << numbers[i] << ", ";
	}
    cout << numbers[n_numbers-1];

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
	for(int i = 0; i<n_ops-1; i++)
	{
		cout << ops[i] << ", ";
	}
    cout << ops[n_ops-1];

	cout << endl;
}

double primary(int beg1, int end1, int offset1 = 0)
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

double secondary(int beg, int end, int offset = 0)
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

void startClear()
{
	for(int i = 0; i<numbers_len; i++)
	{
		numbers[i] = 0;
		float_reminder[i] = 0;
		ops[i] = 0;
	}

	iter = 0;
	n_numbers = 0;
	
	opsIter = 0;
	n_ops = 0;
	bracketCount = 0;
	highestStep = 0;

	a = "";
	b = "";
	x = 0;
}

int main()
{
	cout << "Calculator test mk1 \n";
	while(1)
	{
		startClear();
		getline(cin, a);
		if(a == "quit"){ return 0; };

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
		
		   for(int i = 0; i<a.size(); i++)
		   {
		       if(a[i] == ' '){ continue; }
		       else if(a[i] == '.' && !(a[i-1] - 48 >= 0 && a[i-1] - 48 < 10)){ b += "0."; b += a[i]; }
		       else{ b += a[i]; }
		if(a[i] == ')'){bracketCount++;}
	    }
	    
	    printB();
	    cout << bracketCount << endl;
	 
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
			
			/*
		
		   1 + (2 + 3)
		   concept

		   (begining)
		   add bracket conter )
		   
		   find closed bracket
		   then move back
		   find open
		   check if something in front (later)
		   calculate
		   change rest to 0 and +	
	       and then you done, easy right ?
	  */
		
	    int lastInt = 0;
		      
	    for(int i = 0; i<bracketCount; i++)
	    {
		for(int j = lastInt; j<b.size(); j++)
		{
		    if(b[j] == ')')
		    {
			cout << "Bracket found" << endl;
			for(int k = j; k>=0; k--)
			{
			    if(b[k] == '(')
			    {
				cout << "Other(starting) bracket found" << endl;
				cout << "Starting and ending indexes are " << k << " " << j << endl;
				    printNumbres();
				 printOps();   
				    
				 //DO THE THINGY
				 bool hasSec = 0;       
				 for(int z = k; z<j+1; z++)
				 {
				     cout << b[z];
				     if(b[z] == '*' || b[z] == '/'){ hasSec = 1; break; }   
				 }              
				 if(hasSec)
				 {
				    
				 }
				 else
				 {
				     int tempZB = b[k+1] - 48;
				     cout << "First one " << tempZB << endl;
				     for(int z = k+2; z<j; z++)
				     {
					 cout << "ZBROJI" << b[z] << endl;
					 if(b[z-1] == '+'){ tempZB += b[z]-48; }
					 else if(b[z-1] == '-'){ tempZB -= b[z]-48; }
				     }              
				     
				     cout << tempZB << endl; 
				 }
				    
				 //rijesi se zagrada i to govno         
				 bool secondOutside = 0;
				 if(secondOutside)
				 {}
				 else
				 {
				     //nema mnozenja i dijeljenja izvan zagada
				     
				     
				 }
			    }
			}        
		    }
		}
	    }	
						
	}
		
		cout << "//////////////////////////////////////////////////\n";
		cout << "//                  ANSWER                        \n";
		cout << "//////////////////////////////////////////////////\n";
		cout << x << endl;
		cout << "##################################################\n";
	}	
	return 0;
}
