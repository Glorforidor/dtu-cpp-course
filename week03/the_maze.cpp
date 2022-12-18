#include <iostream>

using namespace std;

typedef enum
{
    wood,
    stone
} material;

typedef struct
{
    int x, y;
    bool isWall;
    material type;
} field;

#define n 16
#define m 12
field playground[n][m];

int x = 5;
int y = 5;

void draw();
void move(char movement); // l r u d
bool isWall();

int main()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            playground[i][j].x = i;
            playground[i][j].y = j;
            playground[i][j].isWall = (i == 0 || i == (n - 1) || (j == 0 && i != 3) || j == (m - 1));
            if (playground[i][j].isWall && !(i == 3 && j == 0))
            {
                playground[i][j].type = stone;
            }
            else
            {
                playground[i][j].type = wood;
            }
        }
    }

    draw();

    while (true)
    {
        char c;
        cin >> c;
        if (c == 'q')
        {
            break;
        }

        move(c);
        draw();
    }

    return 0;
}

bool isWall()
{
    return playground[x][y].isWall;
}

void move(char movement)
{
    switch (movement)
    {
    case 'l':
        if (x != 0)
        {
            x -= 1;
        }
        if (isWall())
        {
            x += 1;
        }
        break;
    case 'r':
        if (x != n - 1)
        {
            x += 1;
        }
        if (isWall())
        {
            x -= 1;
        }
        break;
    case 'u':
        if (y != 0)
        {
            y -= 1;
        }
        if (isWall())
        {
            y += 1;
        }
        break;
    case 'd':
        if (y != m - 1)
        {
            y += 1;
        }
        if (isWall())
        {
            y -= 1;
        }
        break;
    default:
        break;
    }
}

void draw()
{
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            auto f = playground[i][j];
            if (f.isWall)
            {
                cout << "*";
            }
            else
            {
                if (f.y == y && f.x == x)
                {
                    cout << "O";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}