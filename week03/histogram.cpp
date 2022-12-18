#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int l;
    int nInputs;

    cin >> l >> nInputs;

    int num;
    vector<int> inputs;
    while (inputs.size() != nInputs && (cin >> num))
    {
        inputs.push_back(num);
    }

    auto m = max_element(begin(inputs), end(inputs));
    auto k = ceil((double)m[0] / (double)l);

    map<int, int> intervals;

    for (int i = 0; i < l; i++)
    {
        intervals[i * k] = 0;
        for (auto n : inputs)
        {
            auto min = i * k;
            auto max = min + k;
            if (min <= n && n < max)
            {
                intervals[i * k] += 1;
            }
        }
    }

    if (m[0] % l == 0)
    {
        intervals[k] += 1;
    }

    for (auto key : intervals)
    {
        cout << key.first << ": " << key.second << endl;
    }

    return 0;
}
