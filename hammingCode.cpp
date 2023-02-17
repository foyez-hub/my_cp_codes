#include <bits/stdc++.h>
using namespace std;
int getKthBit(int n, int k)
{
    return ((n & (1 << (k - 1))) >> (k - 1));
}

void hamming_code(string data)
{
    int len = data.size();

    map<int, char> mp;
    int i = 1;
    int parity_bit = 0;
    while (len > 0)
    {
        if ((i & (i - 1)) == 0)
        {
            mp[i] = 'p';
            parity_bit++;
        }
        else
        {
            mp[i] = data[len - 1];
            len--;
        }
        i++;
    }

    map<int, int> parity;
    int lp = pow(2, parity_bit) - 1;
    for (int p = 1; p <= parity_bit; p++)
    {
        int ct = 0;
        for (int k = 0; k <= lp; k++)
        {

            if (getKthBit(k, p) == 1)
            {
                if (mp[k] == '1')
                {

                    ct++;
                }
            }
        }

        if (ct % 2 == 1)
        {
            parity[p] = 1;
        }
        else
        {
            parity[p] = 0;
        }
    }
    cout << "The hamming code for given data is : ";

    int pp = 1;
    for (int i = 1; i <= mp.size(); i++)
    {
        if (mp[i] == 'p')
        {
            if (parity[pp] == 1)
                mp[i] = '1';
            else
                mp[i] = '0';

            pp++;
        }
        cout << mp[i];
    }
    cout << endl;
}

void error_detection(string recive)
{
    int parity_bit_cnt = 0;
    for (int i = 1; i <= recive.size(); i++)
    {
        if ((i & (i - 1)) == 0)
        {
            parity_bit_cnt++;
        }
       
    }

    map<int, int> parity;
    int lp = pow(2, parity_bit_cnt) - 1;
    for (int p = 1; p <= parity_bit_cnt; p++)
    {
        int ct = 0;
        for (int k = 1; k <= recive.size(); k++)
        {

            if (getKthBit(k, p) == 1)
            {

                if (recive[k - 1] == '1' && (k & (k - 1)) != 0)
                {

                    ct++;
                }
            }
        }
        if (recive[p - 1] == '1')
            ct++;

        if (ct % 2 == 1)
        {
            parity[p] = 1;
        }
        else
        {
            parity[p] = 0;
        }
    }
    //finding which bit has ans error
    int sum = 0;
    for (int i = 1; i <= parity_bit_cnt; i++)
    {
        if (parity[i] == 1)
        {
            sum += pow(2, i - 1);
        }
    }
    //flipping that error bit
    cout << "There is a error in " << sum << "th bit " << endl;
    if (recive[sum - 1] == '0')
    {
        recive[sum - 1] = '1';
    }
    else
        recive[sum - 1] = '0';

    cout << "The corrected code is: " << recive << endl;
}
int main()
{
    cout << "Enter the data in string format" << endl;
    string data;
    cin >> data;
    hamming_code(data);
    cout << "Enter the received code: " << endl;
    string rr;
    cin >> rr;
    error_detection(rr);
}