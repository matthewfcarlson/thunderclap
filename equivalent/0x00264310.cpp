// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00264310 @ 0x00264310
struct Sink {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual unsigned int vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual bool vfn23();
};

extern char DAT_004e7c28[0x40000];

void __cdecl thunk_FUN_002710d0(Sink **out, const char *name, int a, int b, int c, int d, int e, int f);

class Stream {
public:
    char pad0[8];
    Sink *sink;              // 0x8
    char open;               // 0xc
    char pad1;
    char buffered;           // 0xe
    char pad2;
    unsigned int size;       // 0x10
    char pad3[0x1c - 0x14];
    int bank;                // 0x1c
    char pad4[0x30 - 0x20];
    unsigned int limit;      // 0x30
    char pad5[4];
    unsigned int capacity;   // 0x38
    void FUN_00264050(char *other);
    void FUN_002640f0();
    void FUN_00264310(const char *name);
};

void Stream::FUN_00264310(const char *name)
{
    thunk_FUN_002710d0(&sink, name, 0, 0, 1, 0, 1, 1);
    if (sink != 0) {
        FUN_002640f0();
        if (sink->vfn23()) {
            open = 1;
            unsigned int n = sink->vfn15();
            size = n;
            if (!buffered) {
                limit = n;
                capacity = n;
                return;
            }
            if (n < 0x20000) {
                bank = 1;
                capacity = n;
            } else {
                capacity = 0x20000;
            }
            FUN_00264050(DAT_004e7c28 + ((bank == 0) << 17));
            FUN_002640f0();
            return;
        }
    }
    open = 0;
}
