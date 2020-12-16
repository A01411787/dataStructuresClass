#include <iostream>
#include "ABB.h"

using namespace std;

int main()
{
    ABB t;
    t.meterABB(12);
    t.meterABB(3);
    t.meterABB(14);
    t.meterABB(1);
    t.Print();
    cout<<endl;

    return 0;
}

