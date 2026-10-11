// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 47/48, incomplete)
// FUN_0007a230 @ 0x0007a230
struct Cell {
    int id;
    int pad04;
    int row;
    int col;
    int count;
    char pad14[0x2c - 0x14];
    char active;
    char pad2d[0x48 - 0x2d];
};

struct Rng {
    unsigned int a;
    unsigned int b;
};
extern Rng* DAT_004e5acc;

struct Grid {
    char pad0[0x191c];
    Cell cells[0x400];
    int FUN_0007a230(int idA, int idB, int rowIdx, int span);
};

int Grid::FUN_0007a230(int idA, int idB, int rowIdx, int span)
{
    int list[14];
    int n = 0;
    int lim = span - span % 2;
    Cell* c = &cells[rowIdx * 14];
    for (int i = 0; i < 14; i += 2) {
        if (!c[0].active)
            break;
        if (c[0].count < 3 && (c[0].id == idA || c[0].id == idB) && (i < lim || i > lim + 1)) {
            int r = c[0].row;
            int q = c[0].col;
            if (r == -1 || q == -1 || !cells[r * 14 + q].active || cells[r * 14 + q].count < 3) {
                list[n] = i;
                n++;
            }
        }
        if (!c[1].active)
            break;
        if (c[1].count < 3 && (c[1].id == idA || c[1].id == idB) && (i + 1 < lim || i + 1 > lim + 1)) {
            int r = c[1].row;
            int q = c[1].col;
            if (r == -1 || q == -1 || !cells[r * 14 + q].active || cells[r * 14 + q].count < 3) {
                list[n] = i + 1;
                n++;
            }
        }
        c += 2;
    }
    if (n == 0)
        return -1;
    DAT_004e5acc->a = (DAT_004e5acc->a & 0xffff) * 0x9069 + (DAT_004e5acc->a >> 16);
    DAT_004e5acc->b = (DAT_004e5acc->b & 0xffff) * 0x4650 + (DAT_004e5acc->b >> 16);
    unsigned int v = (DAT_004e5acc->a << 16) + (DAT_004e5acc->b & 0xffff);
    return list[(int)(v % (unsigned int)n) % n];
}
