// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 28/28)
// FUN_00264590 @ 0x00264590
struct Sink_264590 {
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
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual bool vfn20();
    virtual void vfn21();
};
struct Clock_264590 {
    void FUN_00264d20();
};
extern Clock_264590 *DAT_00527c58;
extern char DAT_004e7c28[0x40000];
unsigned int FUN_00267f80();

class Stream {
public:
    char pad0[8];
    Sink_264590 *sink;              // 0x8
    char pad1[1];
    char fd;                 // 0xd
    char pad2;
    char notify;             // 0xf
    char pad3[0x14 - 0x10];
    int total;               // 0x14
    char pad4[0x1c - 0x18];
    int bank;                // 0x1c
    char pad5[0x28 - 0x20];
    char *buffer;            // 0x28
    unsigned int pos;        // 0x2c
    unsigned int limit;      // 0x30
    unsigned int capacity;   // 0x34
    char pad6[4];
    unsigned int pending;    // 0x3c
    unsigned int interval;   // 0x40
    unsigned int lastTime;   // 0x44
    void FUN_00263fd0(const void *src, char *dst, int n, int flag);
    void FUN_00264050(char *other);
    void FUN_00264140(const void *src, int count, int size);
    bool FUN_00264590(const void *data, int count, int size, int flag);
};

bool Stream::FUN_00264590(const void *data, int count, int size, int flag)
{
    int n = count * size;
    unsigned int used = pos;
    pending += n;
    if (used + n <= limit) {
        FUN_00263fd0(data, buffer + used, n, flag);
        pos += n;
        total += n;
    } else {
        const char *src = (const char *)data;
        while (n > 0) {
            int chunk = n;
            if (pos + n > limit)
                chunk = limit - pos;
            FUN_00263fd0(src, buffer + pos, chunk, flag);
            pos += chunk;
            total += chunk;
            n -= chunk;
            src += chunk;
            if (n <= 0)
                break;
            if (sink != 0) {
                if (fd) {
                    sink->vfn21();
                } else {
                    while (!sink->vfn20()) {
                        DAT_00527c58->FUN_00264d20();
                        lastTime = FUN_00267f80();
                    }
                }
            }
            int next = (bank == 0);
            pos = 0;
            limit = capacity;
            buffer = DAT_004e7c28 + (next << 17);
            bank = next;
            FUN_00264050(DAT_004e7c28 + ((next == 0) << 17));
        }
    }
    if (notify)
        FUN_00264140(data, count, size);
    if (!fd) {
        if (pending >= 0x400) {
            if (FUN_00267f80() - lastTime >= interval) {
                DAT_00527c58->FUN_00264d20();
                lastTime = FUN_00267f80();
            }
            pending = 0;
        }
    }
    return true;
}
