// number of frames
// number of pages

#include <iostream>

using namespace std;

int main ()
{
    int f, n, i, j, k;
	cout << "\nEnter the No of frames: ";
	cin >> f;
	cout << "\nEnter No of Pages in Reference String: ";
	cin >> n;

    int pages[n];
    int alloc[f] = {-1};
    cout << "\nEnter Page IDs: ";
	for (int i = 0; i < n; i++)
		cin >> pages[i];
    
    // fifo
    int ind=0, fault = 0;

    for ( i = 0; i < n; i++)
    {
        int flag = 0; // to check if page hits/faults
        // for every page in seq: check if already present
        for ( j = 0; j < n; j++)
        {
            if(alloc[j] == pages[i])
                flag=1;
        }
        if(flag != 1)
        {   // insert/replace page
            alloc[ind] = pages[i];
            ind = (ind+1) % f;
            fault++;
        }

        // print alloc and request seq       
    }
    
    return 0;
}