// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 20/20)
// FUN_00289070 @ 0x00289070
#include "gen/pure3d.h"
void* FUN_0008d690(unsigned int size);

struct Stream_289070 {
    char pad[0xc];
    char FUN_002647e0(void* dst, int a, int size, int b);
};

class Field_289070 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Measure(int* outA, int* outB, int key, int value);
};

struct Table_289070 {
    Field_289070* FUN_0028b020(int key);
};

struct AnimationMemoryBlock_nv_289070 {
    pure3d::AnimationMemoryBlock* FUN_00288820(unsigned int total, unsigned int extra);
};

struct Reader_289070 {
    char pad000[0x280];
    int pad280;
    Stream_289070* stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct Layout_289070 {
    char pad00[0x14];
    Table_289070* table;
    char pad18[8];
    int count;
    pure3d::AnimationMemoryBlock* FUN_00289070(Reader_289070* r);
};

struct Frame_289070 {
    unsigned int x2;
    unsigned int n;
    unsigned int key;
    unsigned int value;
    int outA;
    int outB;
    unsigned int skipC;
    unsigned int skipB;
    unsigned int pad38;
    unsigned int total;
};

pure3d::AnimationMemoryBlock* Layout_289070::FUN_00289070(Reader_289070* r)
{
    Frame_289070 f;
    r->stream->FUN_002647e0(&f.total, 1, 4, 1);
    r->stream->FUN_002647e0(&f.total, 1, 4, 1);
    if (f.total == 0)
        return 0;
    f.total = f.total << 5;
    unsigned int extra = 0;
    while (r->FUN_002669f0() != 0) {
        int id = r->FUN_00266a30();
        if (id == 0x121006) {
            r->FUN_00266be0();
            return 0;
        }
        if (id == 0x121007) {
            r->stream->FUN_002647e0(&f.skipB, 1, 4, 1);
            r->stream->FUN_002647e0(&f.key, 1, 4, 1);
            r->stream->FUN_002647e0(&f.n, 1, 4, 1);
            extra += f.n * 4;
            for (unsigned int i = f.n; i != 0; i--) {
                Field_289070* fld = table->FUN_0028b020(f.key);
                if (fld != 0) {
                    r->stream->FUN_002647e0(&f.value, 1, 2, 1);
                    fld->Measure(&f.outA, &f.outB, f.key, f.value);
                    f.total += f.outA;
                    extra += f.outB;
                }
            }
        } else if (id == 0x121400) {
            r->stream->FUN_002647e0(&f.skipC, 1, 4, 1);
            r->stream->FUN_002647e0(&f.x2, 1, 4, 1);
            this->count = f.x2;
            extra += f.x2 * 24;
        }
        r->FUN_00266be0();
    }
    pure3d::AnimationMemoryBlock* res = (pure3d::AnimationMemoryBlock*)FUN_0008d690(0x20);
    if (res == 0)
        return 0;
    return ((AnimationMemoryBlock_nv_289070*)(res))->FUN_00288820(f.total, extra);
}
