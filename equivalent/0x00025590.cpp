// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 13/14, incomplete)
// FUN_00025590 @ 0x00025590
struct Mat4_25590 { float m[16]; };
struct Name_25590 {
    int lo;
    int hi;
    void FUN_0027af00();
    void FUN_0027af50();
    void FUN_0027af70(int v);
};
struct Record_25590 {
    char pad0[0x44];
    char fixed;             // 0x44
    char pad1[3];
    int key;                // 0x48
};
struct Layout_25590 {
    void FUN_00283a40(Name_25590 *n, const Mat4_25590 *m, int a, int v);
};
Layout_25590 *FUN_0027f250();

struct Entry_25590 {              // 0x68 bytes
    Mat4_25590 mat;               // 0x00
    Name_25590 nameA;             // 0x40
    Name_25590 nameB;             // 0x48
    int key;                // 0x50
    unsigned int stamp;     // 0x54
    int f58;
    int f5c;
    int f60;
    char fixed;             // 0x64
    char pad[3];
};

class Mgr_25590 {
public:
    char pad0[0x58c];
    int count;              // 0x58c
    Entry_25590 entries[16];      // 0x590
    void FUN_00025590(Record_25590 *rec, int a1, int a2, int a3, int a4, const Mat4_25590 *mat, int a6, unsigned int stamp);
};

void Mgr_25590::FUN_00025590(Record_25590 *rec, int a1, int a2, int a3, int a4, const Mat4_25590 *mat, int a6, unsigned int stamp)
{
    int n = count;
    int i = 0;
    if (n > 0) {
        Entry_25590 *e = &entries[0];
        do {
            if (e->key == rec->key) {
                if (e->stamp > stamp) return;
                e->nameA.FUN_0027af70(a1);
                e->f58 = a2;
                e->nameB.FUN_0027af70(a3);
                e->f5c = a4;
                e->mat = *mat;
                e->stamp = stamp;
                e->f60 = a6;
                e->fixed = rec->fixed;
                return;
            }
            i++;
            e++;
        } while (i < count);
    }
    if (n >= 16) {
        Name_25590 name;
        int v;
        name.FUN_0027af00();
        if (rec->fixed) {
            name.FUN_0027af70(a3);
            v = a4;
        } else {
            name.FUN_0027af70(a1);
            v = a2;
        }
        if ((name.lo | name.hi) != 0) {
            FUN_0027f250()->FUN_00283a40(&name, mat, a6, v);
        }
        name.FUN_0027af50();
        return;
    }
    Entry_25590 *e = &entries[n];
    e->key = rec->key;
    e->nameA.FUN_0027af70(a1);
    e->f58 = a2;
    e->nameB.FUN_0027af70(a3);
    e->f5c = a4;
    e->mat = *mat;
    e->stamp = stamp;
    e->f60 = a6;
    e->fixed = rec->fixed;
    count++;
}
