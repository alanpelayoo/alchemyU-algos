/*
Implementation of RSA algorithm in C++
The RSA algorithm is based on the idea that it's very easy to find the product of two prime numbers, 
yet extremely difficult to factor out those two prime numbers if you have the product.
Public key: (e,n)
Secret key: (d,n)
*/

#include <iostream>
#include <math.h>
using namespace std;
// find gcd
int gcd(int a, int b)
{
    int t;
    while (1)
    {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}

int main(){
    // Choose two prime numbers
    int p=13, q=11;

    //Compute n
    int n = p*q;
    
    
    //Compute phi
    int phi = (p-1)*(q-1);

    int track;
    int e;

    //Calcualte coprime to phi
    for (int i =2; i<phi; i++){
        track = gcd(i,phi);
        if(track ==1){
            e = i;
            break;
        }
    }
    //choosing d such that it satisfies d*e = 1 mod phi, not correct.
    double d1 = 1.0/e;
    double phi_2 = (double)phi;
    double d = fmod(d1, phi_2);


    cout << "N value "<<n<<"\n";
    cout << "phi value "<<phi<<"\n";
    cout << "Coprime e "<<e<<"\n";
    cout << "Private key: ("<<e<<","<<n<<") \n";

    cout << "Decrypt value "<<d<<"\n";
}