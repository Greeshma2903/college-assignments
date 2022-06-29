//  [C] Write a C++ program to study concept of constructors in derived classes.

#include <iostream>
using namespace std;

// BASE CLASS 1
class Alpha
{
    int a;

public:
    Alpha(int);
    void show_alpha();
};
Alpha::Alpha(int val)
{
    a = val;
    cout << "\nAlpha initialized";
}
void Alpha::show_alpha()
{
    cout << "\na = " << a << endl;
}

// BASE CLASS 2
class Beta
{
    int b;

public:
    Beta(int);
    void show_beta();
};
Beta::Beta(int val)
{
    b = val;
    cout << "\nBeta initialized";
}
void Beta::show_beta()
{
    cout << "\nb = " << b << endl;
}

// DERIVED CLASS
class Gamma : public Beta, public Alpha
{
    int j, k;

public:
    Gamma(int w, int x, int y, int z) : Alpha(w), Beta(x)
    {
        j = y;
        k = z;
        cout << "\nGamma initialized";
    }
    void show_gamma();
};
void Gamma::show_gamma()
{
    cout << "\nj = " << j << "\nk = " << k << endl;
}

// MAIN FUNCTION ---------------------->
int main()
{
    Gamma g(12, 10, 35, 40);
    cout << endl;
    g.show_alpha();
    g.show_beta();
    g.show_gamma();

    return 0;
}