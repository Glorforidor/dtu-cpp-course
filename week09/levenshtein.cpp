#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int levensthtein(string u, string v)
{
    if (u.length() == 0)
    {
        return v.length();
    }
    if (v.length() == 0)
    {
        return u.length();
    }

    string uc = u;
    string vc = v;
    uc.erase(0, 1);
    vc.erase(0, 1);

    // if same start character just recurse again with the rest of the strings.
    if (u[0] == v[0])
    {
        return levensthtein(uc, vc);
    }

    int x = levensthtein(uc, v);
    int y = levensthtein(u, vc);
    int z = levensthtein(uc, vc);

    // by adding 1 to the minimum, fixes that each recursion should have had a + 1.
    return 1 + min(min(x, y), z);
}

int main()
{
    string u;
    string v;
    cin >> u >> v;

    cout << levensthtein(u, v) << endl;

    return 0;
}