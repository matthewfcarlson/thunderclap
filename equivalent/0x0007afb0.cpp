// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 24/24)
// FUN_0007afb0 @ 0x0007afb0
extern float DAT_004dd048;
extern float DAT_004dd04c;

struct V3 {
    float x, y, z;
};

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022ba70(float angle);
    void FUN_0022c3b0(const V3* in, V3* out);
};

struct Cell {
    V3 b2;
    V3 b1;
    int z;
    int key;
    char pad20[8];
    int cnt;
    int pad2c[3];
    int f38;
    int f3c;
    int f40;
    int f44;
};

struct Frame {
    float fu;
    int turn;
    float fx;
    int pad0c;
    float fz;
    unsigned int dir;
    Matrix m1;
    Matrix m2;
};

class Grid {
public:
    int tbl[0x1904 / 4];
    Cell cells[98];

    int FUN_00079190(int a, int b);
    void FUN_0007afb0(int row, int col, int n, int swap, V3* p1, V3* p2);
};

void Grid::FUN_0007afb0(int row, int col, int n, int swap, V3* p1, V3* p2)
{
    Frame f;
    int key = cells[row * 14].key;
    int q = (key - 1) / 30;
    int rem = (key - 1) % 30;
    int t1 = -((rem % 2) != 0) - q * 2;
    f.fx = (float)t1 * 77.942283630371f;
    f.fz = ((float)rem - 0.5f) * -135.0f;
    f.m1.FUN_0022b980();
    f.turn = (short)tbl[key * 2];
    f.m1.FUN_0022ba70((float)f.turn * 1.0471975803375244f);
    f.m2.FUN_0022b980();
    f.turn = 6 - (short)tbl[key * 2];
    f.m2.FUN_0022ba70((float)f.turn * 1.0471975803375244f);

    Cell& c = cells[row * 14 + col];
    *p1 = c.b2;
    *p2 = c.b1;
    f.dir = c.f40;
    int r = FUN_00079190(c.z, c.f40);
    float val = ((tbl[key * 2 - 1] >> (r * 4)) & 2) ? 8.5f : 7.0f;
    f.fu = (float)n + val - 2.0f + 1.0f;
    p1->x = p1->x - f.fx;
    p1->z = p1->z - f.fz;
    p2->x = p2->x - f.fx;
    p2->z = p2->z - f.fz;
    f.m1.FUN_0022c3b0(p1, p1);
    f.m1.FUN_0022c3b0(p2, p2);
    if (f.dir <= 3) {
        switch (f.dir) {
        case 0: {
            float a = DAT_004dd048 * f.fu;
            p1->x = p1->x + a;
            p2->x = p2->x + a;
            float b = DAT_004dd04c * f.fu;
            if (r == 0)
                p2->z = p2->z + b;
            else if (r == 6)
                p1->z = p1->z + b;
            else if (r == 1)
                p2->z = p2->z - b;
            else
                p1->z = p1->z - b;
            break;
        }
        case 1: {
            float a = DAT_004dd048 * f.fu;
            p1->x = p1->x - a;
            p2->x = p2->x - a;
            float b = DAT_004dd04c * f.fu;
            if (r == 0)
                p1->z = p1->z - b;
            else if (r == 6)
                p2->z = p2->z - b;
            else if (r == 1)
                p1->z = p1->z + b;
            else
                p2->z = p2->z + b;
            break;
        }
        case 2:
            p1->z = f.fu + p1->z;
            p2->z = f.fu + p2->z;
            break;
        case 3:
            p1->z = p1->z - f.fu;
            p2->z = p2->z - f.fu;
            break;
        }
    }
    f.m2.FUN_0022c3b0(p1, p1);
    f.m2.FUN_0022c3b0(p2, p2);
    p1->x = f.fx + p1->x;
    p1->z = f.fz + p1->z;
    p2->x = f.fx + p2->x;
    p2->z = f.fz + p2->z;
    if (swap == 1) {
        V3 t = *p1;
        *p1 = *p2;
        *p2 = t;
    }
}
