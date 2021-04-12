#include <iostream>
#include <string>
#include<fstream>
#include <immintrin.h>
#include <random>

using namespace std;


int rdrand32_step (uint32_t *rand)
{
	unsigned char ok;

	asm volatile ("rdrand %0; setc %1"
		: "=r" (*rand), "=qm" (ok));

	return (int) ok;
}


int main()
{

    int n=100000;

    string linia;
    fstream plik;


    plik.open("timetest.txt", ios::out | ios::trunc);
    if(plik.good() == true)
    {

       for (int i=0;i<n;i++)
    {

        uint32_t sum = 0;
        rdrand32_step(&sum);

        sum = sum%256;


        plik << sum  << endl;
    }
        plik.close();
    }


    return 1;
}
