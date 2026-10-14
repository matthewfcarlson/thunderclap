// STATUS: equivalent (tools/equiv.py level 3: 144 inputs, branch coverage 26/26)
// FUN_0007b4f0 @ 0x0007b4f0
struct Raw3_7b4f0 {
    int a;
    int b;
    int c;
};

class Tracker_7b4f0 {
public:
    char pad00[0x10];
    int state;
    char pad14[0x38 - 0x14];
    int f38;
    int f3c;
    void FUN_00084920(Raw3_7b4f0 d1, Raw3_7b4f0 d2, Raw3_7b4f0 d3);
    void FUN_00083d20(int v);
};

struct Cell_7b4f0 {
    Raw3_7b4f0 b2;
    Raw3_7b4f0 b1;
    int z;
    int key;
    char pad20[8];
    int cnt;
    char pad2c[0x48 - 0x2c];
};

struct Flags_7b4f0 {
    unsigned char a;
    unsigned char b;
};

class Grid_7b4f0 {
public:
    char pad0000[0x1904];
    Cell_7b4f0 cells[98];
    Flags_7b4f0 flags[7];
    char pad34a2[0x374c - 0x34a2];
    Tracker_7b4f0* objs[8];

    int FUN_0007a200(int key);
    int FUN_0007a230(int a, int b, int c, int d);
    void FUN_0007a3b0(int a, int b, int* out1, int* out2);
    void FUN_0007b4f0(int idx);
};

void Grid_7b4f0::FUN_0007b4f0(int idx)
{
    Tracker_7b4f0* o = objs[idx];
    if (o->state == 3) {
        int key = o->f38;
        int i = 0;
        while (i < 7 && cells[i * 14].key != key)
            i++;
        if (i == 7)
            i = -1;
        if (flags[i].a)
            return;
        int b = o->f3c;
        int r = FUN_0007a230(2, 4, i, b);
        if (r == -1)
            return;
        cells[i * 14 + b].cnt = cells[i * 14 + b].cnt - 1;
        cells[i * 14 + r].cnt = cells[i * 14 + r].cnt + 1;
        Cell_7b4f0& d = cells[i * 14 + r];
        Raw3_7b4f0 first;
        first.a = cells[i * 14].key;
        first.b = r;
        first.c = d.z;
        objs[idx]->FUN_00084920(first, d.b2, d.b1);
        flags[i].a = 1;
    } else if (o->state == 4) {
        int j = FUN_0007a200(o->f38);
        if (flags[j].b)
            return;
        int b = o->f3c;
        int r = FUN_0007a230(3, 5, j, b);
        if (r == -1)
            return;
        cells[j * 14 + b].cnt = cells[j * 14 + b].cnt - 1;
        cells[j * 14 + r].cnt = cells[j * 14 + r].cnt + 1;
        Cell_7b4f0& d = cells[j * 14 + r];
        Raw3_7b4f0 first;
        first.a = cells[j * 14].key;
        first.b = r;
        first.c = d.z;
        objs[idx]->FUN_00084920(first, d.b2, d.b1);
        flags[j].b = 1;
    } else if (o->state == 11) {
        int j = FUN_0007a200(o->f38);
        flags[j].a = 0;
        objs[idx]->FUN_00083d20(0);
    } else if (o->state == 12) {
        int j = FUN_0007a200(o->f38);
        flags[j].b = 0;
        objs[idx]->FUN_00083d20(0);
    } else if (o->state == 13) {
        int j = FUN_0007a200(o->f38);
        int b = o->f3c;
        int row;
        FUN_0007a3b0(j, b, &row, &idx);
        if (row == -1)
            return;
        if (idx == -1)
            return;
        Cell_7b4f0& d = cells[row * 14 + idx];
        Raw3_7b4f0 first;
        first.a = cells[row * 14].key;
        first.b = idx;
        first.c = d.z;
        o->FUN_00084920(first, d.b2, d.b1);
        cells[j * 14 + b].cnt = cells[j * 14 + b].cnt - 1;
        d.cnt = d.cnt + 1;
    }
}
