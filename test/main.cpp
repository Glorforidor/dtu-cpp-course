#include <iostream>
#include <vector>
using namespace std;

vector<int> dataSet;

void collectData()
{
    int x;
    while (true)
    {
        cin >> x;
        dataSet.push_back(x);
        char c = cin.get();
        if (c == '\n')
            break;
    }
}
void reverse(vector<int> &v, int start, int end)
{
    if (start < end)
    {
        int tmp = v[start];
        v[start] = v[end];
        v[end] = tmp;
        reverse(v, start + 1, end - 1);
    }
}
void displayData()
{
    for (auto e : dataSet)
    {
        cout << e << " ";
    }
    cout << endl;
}
int main()
{
    collectData();
    int start = 0;
    int end = dataSet.size() - 1;
    reverse(dataSet, start, end);
    displayData();
    return 0;
}