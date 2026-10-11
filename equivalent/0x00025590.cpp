// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 13/14, incomplete)
// FUN_00025590 @ 0x00025590
struct Mat4 { float m[16]; };
struct Name {
    int lo;
    int hi;
    void FUN_0027af00();
    void FUN_0027af50();
    void FUN_0027af70(int v);
};
struct Record {
    char pad0[0x44];
    char fixed;             // 0x44
    char pad1[3];
    int key;                // 0x48
};
struct Layout {
    void FUN_00283a40(Name *n, const Mat4 *m, int a, int v);
};
Layout *FUN_0027f250();

struct Entry {              // 0x68 bytes
    Mat4 mat;               // 0x00
    Name nameA;             // 0x40
    Name nameB;             // 0x48
    int key;                // 0x50
    unsigned int stamp;     // 0x54
    int f58;
    int f5c;
    int f60;
    char fixed;             // 0x64
    char pad[3];
};

class Mgr {
public:
    char pad0[0x58c];
    int count;              // 0x58c
    Entry entries[16];      // 0x590
    void FUN_00025590(Record *rec, int a1, int a2, int a3, int a4, const Mat4 *mat, int a6, unsigned int stamp);
};

void Mgr::FUN_00025590(Record *rec, int a1, int a2, int a3, int a4, const Mat4 *mat, int a6, unsigned int stamp)
{
    int n = count;
    int i = 0;
    if (n > 0) {
        Entry *e = &entries[0];
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
        Name name;
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
    Entry *e = &entries[n];
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
