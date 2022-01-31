// 1$ = +74.52Rs
// 2$ = +149.04Rs

// * Scientific notation: gives power of 'e'
// * Fixed notation: doesn't give power of 'e'

#include <iostream>
#include <iomanip>
using namespace std;

ostream &showDollar(ostream &output)
{
    output << "$";
    return output;
}

ostream &rupee(ostream &output)
{
    output << "Rs";
    return output;
}

ostream &form(ostream &output)
{
    output.setf(ios::showpos);
    output.setf(ios::showpoint);
    output.precision(2);
    output << setiosflags(ios::fixed);
    return output;
}

int main()
{
    int i;
    float dollar = 74.52;
    for (i = 1; i <= 2; ++i)
    {
        cout << i << showDollar << " = " << form << i * dollar << rupee << endl;
        cout << resetiosflags(ios::showpos);
    }

    return 0;
}