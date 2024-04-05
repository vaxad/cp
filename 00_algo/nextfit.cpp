// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main()
{
    // Write C++ code here
    int nb, np, block[100], process[100], avail = 0, last;
    bool used[100] = {false};
    cout << "Next Fit Algorithm: ";
    cout << "enter number of blocks: ";
    cin >> nb;
    for (int i = 0; i < nb; i++)
    {
        cout << "enter size of block " << i + 1 << ": ";
        cin >> block[i];
        avail += block[i];
    }
    cout << "enter last allocated block: ";
    cin >> last;
    cout << "enter number of processes: ";
    cin >> np;
    for (int i = 0; i < np; i++)
    {
        cout << "enter size of process " << i + 1 << ": ";
        cin >> process[i];
    }
    for (int i = 0; i < np; i++)
    {
        int j = last;
        while (j < 2 * nb)
        {
            cout << "(checking block " << (j % nb) + 1 << ")" << endl;
            if (process[i] <= block[(j % nb)])
            {
                if (!used[(j % nb)])
                {
                    cout << "process" << i + 1 << " allocated in block " << (j % nb) + 1 << endl;
                    block[(j % nb)] -= process[i];
                    used[(j % nb)] = true;
                    last = (j % nb) + 1;
                    break;
                }
            }
            else if ((j) == 2 * nb - 1)
            {
                cout << "process" << i + 1 << " could not be allocated in any block " << endl;
            }
            j++;
        }
    }
    int frag = 0;
    for (int i = 0; i < nb; i++)
    {
        frag += block[i];
    }
    cout << avail << " available and " << frag << " used\n";
    float ratio = (float)(avail - frag) / (float)(avail);
    cout << "ratio " << ratio;
    return 0;
}