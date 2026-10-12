// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 20/20)
// FUN_00289070 @ 0x00289070
void* FUN_0008d690(unsigned int size);

struct Stream {
    char pad[0xc];
    char FUN_002647e0(void* dst, int a, int size, int b);
};

class Field {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Measure(int* outA, int* outB, int key, int value);
};

struct Table {
    Field* FUN_0028b020(int key);
};

struct Result {
    Result* FUN_00288820(unsigned int total, unsigned int extra);
};

struct Reader {
    char pad000[0x280];
    int pad280;
    Stream* stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct Layout {
    char pad00[0x14];
    Table* table;
    char pad18[8];
    int count;
    Result* FUN_00289070(Reader* r);
};

struct Frame {
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

Result* Layout::FUN_00289070(Reader* r)
{
    Frame f;
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
                Field* fld = table->FUN_0028b020(f.key);
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
    Result* res = (Result*)FUN_0008d690(0x20);
    if (res == 0)
        return 0;
    return res->FUN_00288820(f.total, extra);
}
