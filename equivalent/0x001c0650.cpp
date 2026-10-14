// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 10/10)
// FUN_001c0650 @ 0x001c0650
// Shake::FUN_001c0650 @ 0x001c0650: reset and start the shake for a looked-up entry
struct Entry {
    int a;
    float b;
    int c;
    int d;
};

struct Child {
    char pad0[0xc];
    char flag0c;
};

struct Track {
    char pad0[8];
    int f08;
    int f0c;
    float f10;
    int f14;
};

class Shake {
public:
    float value;            // 0x00
    int count;              // 0x04
    Entry *volatile entries; // 0x08 (re-read between the stores: it can alias this)
    char pad0c;
    char flag0d;
    char pad0e[0x12];
    int mode;               // 0x20
    char flag24;
    char pad25[7];
    Child *child;           // 0x2c
    char pad30[0xc];
    Track *tracks;          // 0x3c
    char pad40[0x14];
    char flag54;
    char flag55;
    int FUN_001be0e0(int a, int b);
    void FUN_001c0360(int a, int b);
    void FUN_001c0650(int unused, int a, int b);
};

void Shake::FUN_001c0650(int unused, int a, int b)
{
    int idx = FUN_001be0e0(a, b);
    if (idx == -1)
        return;

    count = 0;
    value = -1.0f;
    flag0d = 0;
    flag24 = 0;
    flag55 = 0;
    if (mode == 2)
        child->flag0c = 0;

    FUN_001c0360(unused, 1);

    Track *t = &tracks[idx];
    float f10 = t->f10;
    int f08 = t->f08;
    int f0c = t->f0c;
    if (count > 0) {
        entries->a = 0;
        Entry *e = entries;
        e->c = f08;
        e->d = f0c;
        entries->b = f10;
    }
    flag55 = (flag54 != 0);
}
