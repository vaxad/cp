#include <iostream>
using namespace std;

bool done(int rem[100][100], int nr, int np)
{
    int ctr = 0;
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nr; j++)
        {
            if (rem[i][j] == 0)
                ctr++;
        }
    }
    return ctr == nr * np;
}

int main()
{
    cout << "varad prabhu\n";
    int np, nr;
    cout << "Enter number of processes: ";
    cin >> np;
    cout << "Enter number of resources: ";
    cin >> nr;
    int alloc[100][100], max[100][100], rem[100][100], total[100];
    for (int i = 0; i < nr; i++)
    {
        cout << "Enter total instances of resource " << (char)('A' + i) << ": ";
        cin >> total[i];
    }
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nr; j++)
        {
            cout << "Enter instances of resource " << (char)('A' + j) << " allocated to process " << i + 1 << ": ";
            cin >> alloc[i][j];
            total[j] -= alloc[i][j];
        }
    }
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nr; j++)
        {
            cout << "Enter instances of resource " << (char)('A' + j) << " needed by process " << i + 1 << ": ";
            cin >> max[i][j];
            rem[i][j] = max[i][j] - alloc[i][j];
        }
    }
    cout << "\n allocated matrix : \n";
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nr; j++)
        {
            cout << " " << alloc[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n need matrix : \n";
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nr; j++)
        {
            cout << " " << max[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n remaining matrix : \n";
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nr; j++)
        {
            cout << " " << rem[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n available resources : \n";
    for (int i = 0; i < nr; i++)
    {
        cout << " " << total[i] << " ";
    }
    int c = 1;
    while (c==1)
    {
        for (int i = 0; i < np; i++)
        {
            int completed = 0;
            bool allocate = false;
            cout << "\n\nFor process " << i + 1 << "\n";
            for (int j = 0; j < nr; j++)
            {
                cout << "required " << (char)('A' + j) << ": " << rem[i][j] << " available " << (char)('A' + j) << ": " << total[j] << endl;
                if (rem[i][j] > total[j])
                {
                    allocate = false;
                    break;
                }
                if (rem[i][j] == 0)
                {
                    completed++;
                }
                if (j == nr - 1)
                {
                    allocate = completed == nr ? false : true;
                }
            }
            if (allocate)
            {
                cout << "\nexecuting process " << i + 1;
                for (int j = 0; j < nr; j++)
                {
                    rem[i][j] = 0;
                    total[j] += alloc[i][j];
                }
            }
            cout << "\n available resources : \n";
            for (int i = 0; i < nr; i++)
            {
                cout << " " << total[i] << " ";
            }
        }
        if (done(rem, nr, np))
        {
            cout << "break";
            c=0;
        }
    }

    return 0;
}