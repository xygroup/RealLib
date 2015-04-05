#include <iostream>
#include <iomanip>
#include <ctime>
#include "RealEstimate.h" 
#include "Real.h"

using namespace RealLib;
using namespace std;

template <class Estimate>
Estimate etaylor(unsigned int prec)
{
    Estimate s(0.0);
    Estimate m(1.0);
    prec; // to avoid warning

    for (int i=1; i<=1000; ++i) {
        s += m;
        m /= i;
    }
    return s;
}
CreateNullaryRealFunction(etaylor)

int main()
{
    clock_t starttime = clock();

    InitializeRealLib();

    {
        Real ex(exp(Real(1.0)));
        Real s(etaylor());

        Real diff(ex - s);

        if (diff > 0.0) {
            cout << fixed << setprecision(50);
            cout << "exp(1.0):\t" << ex << endl;
            cout << "taylor: \t" << s << endl;
            cout << "difference:\t" << scientific << diff << endl;
        }

    }

    unsigned pr = FinalizeRealLib();

    clock_t endtime = clock();
    cout << fixed << setprecision(6);
    cout << "prec: " << pr << " time elapsed: " <<
            double(endtime - starttime) / CLOCKS_PER_SEC << endl;

    cin.get();
    return 0;
}
