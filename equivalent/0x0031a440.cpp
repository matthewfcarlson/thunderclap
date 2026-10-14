// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0031a440 @ 0x0031a440
struct Sub {
    char pad0[0x20];
    float w0;                  // sub+0x20 (obj+0x30)
    float w1;                  // sub+0x24 (obj+0x34)
    char pad28[0x60 - 0x28];
    void FUN_0031a830();
};

void *__cdecl FUN_0008d6d0(unsigned int size);

class Buffer {
public:
    char *begin;               // 0x00
    char *cur;                 // 0x04
    char *end;                 // 0x08
    char pad0c[4];
    Sub sub;                   // 0x10
    int f70, f74, f78, f7c;    // 0x70
    unsigned int flags;        // 0x80
    char pad84[4];
    int f88, f8c, f90, f94, f98, f9c, fa0;
    Buffer *FUN_0031a440();
};

Buffer *Buffer::FUN_0031a440()
{
    begin = 0;
    cur = 0;
    end = 0;
    sub.FUN_0031a830();
    f70 = 0;
    f74 = 0;
    f78 = 0;
    f7c = 0;
    flags = 0;
    f88 = 0;
    f8c = 0;
    f90 = 0;
    f94 = 0;
    f98 = 0;
    f9c = 0;
    fa0 = 0;
    begin = (char *)FUN_0008d6d0(0x3e8);
    if (begin != 0) {
        cur = begin;
        end = begin + 0x3e8;
    } else {
        cur = 0;
        end = 0;
    }
    if (flags & 6) {
        if (flags & 4) {
            if (!(flags & 2)) {
                sub.w0 = 0.0f;
                sub.w1 = 1.0f;
            }
        } else {
            sub.w0 = 1.0f;
            sub.w1 = 0.0f;
        }
    }
    return this;
}
