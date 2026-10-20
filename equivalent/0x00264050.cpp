// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00264050 @ 0x00264050
#include "compat/ptr.h"
int __cdecl FUN_0026fd50(hulk_intptr a, int b);
class Stream {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int a, int b, int c);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int v16();
};
class Reader {
public:
    char pad0[8];
    Stream* stream;
    char pad0c[4];
    unsigned int limit;
    char pad14[4];
    unsigned int pos;
    char pad1c[0x34 - 0x1c];
    int lastCount;
    unsigned int chunk;
    void FUN_00264050(int dest);
};
void Reader::FUN_00264050(int dest) {
    if (pos >= limit)
        return;
    unsigned int n = chunk;
    if (pos + n >= limit) {
        int rest = limit - pos;
        stream->v3(dest, FUN_0026fd50(rest, stream->v16()), 1);
        lastCount = rest;
        pos = pos + rest;
        return;
    }
    stream->v3(dest, n, 1);
    pos += n;
    lastCount = n;
}
