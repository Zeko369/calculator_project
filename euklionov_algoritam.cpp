#include <iostream>
#include <math.h>

using namespace std;

long gcd(long a, long b) //euklion algorithm
{
     if(a == 0){ return b; }
     else if(b == 0){ return a; }
    
     if(a < b){ return gcd(a, b%a); }
     else{return gcd(b, a%b); }
}

void printFrac(double input)
{
    double inte = floor(input);
    double frac = input - inte;
    
    const long prec = 1000000;
    
    long _gcd = gcd(round(frac * prec), prec);
    
    long den = prec / _gcd;
    long num = round(frac * prec) / _gcd;
    
    if(inte != 0){ cout << inte << '+'; }
    cout << num << '/' << den << endl;
}

int main()
{
    printFrac(0.5);
    float pero = 1; pero /= 3;
    printFrac(pero);
    printFrac(0.1);
    printFrac(0.235);
    
    return 0;
}

/*
0.33333 -> 1/3

OR maybe all fracs?

double numbers[10][2]; ??
+ string b;

so

first all to frac and then all combine together
?

1 + (2+3)
1/1 + (2/1+3/1)
1/1 + 5/1
6/1 
*/

string b = "1+(2+3)";
double numbers[10][2] = {};
int iter = 0;
bool isNum(char a){ return (a - 48 < 10 && a - 48 >= 0) ? 1 : 0; }

void convertToNums()
{
    for(int i = 0; i<b.size(); i++)
    {
        if(isNum(b[i]))
        {
            numbers[iter] += b[i] - 48;
            if(!(isNum(b[i+1])))
            {
                iter++;
            }
            else
            {
                numbers[iter] *= 10;
            }
        }            

    }
} 

//maybe not
//figure out
