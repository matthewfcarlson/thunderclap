// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ca6b0 @ 0x001ca6b0
struct Id64_1ca6b0 {
    unsigned int lo, hi;
    ~Id64_1ca6b0() throw();
};
union Key_1ca6b0 {
    unsigned __int64 q;
    unsigned int w[2];
};
unsigned __int64 __cdecl FUN_0027b020(const char *name) throw();

struct Request {
    int size;
    int kind;
    int f08;
    int f0c;
    int value;
    int f14;
    Id64_1ca6b0 first;
    Id64_1ca6b0 second;
    int f28;
    int f2c;
    unsigned int keyLo;
    unsigned int keyHi;
    Request *FUN_001ca6b0(Id64_1ca6b0 a, Id64_1ca6b0 b, int c, const char *name, int v);
};

Request *Request::FUN_001ca6b0(Id64_1ca6b0 a, Id64_1ca6b0 b, int c, const char *name, int v)
{
    size = 0;
    kind = 0;
    f08 = 0;
    f0c = 0;
    value = 0;
    f14 = 0;
    first.lo = 0;
    first.hi = 0;
    second.lo = 0;
    second.hi = 0;
    f28 = 0;
    f2c = 0;
    keyLo = 0;
    keyHi = 0;
    first = a;
    second = b;
    size = 0x38;
    kind = 0x14;
    f28 = c;
    Key_1ca6b0 k;
    k.q = FUN_0027b020(name);
    keyLo = k.w[0];
    keyHi = k.w[1];
    value = v;
    return this;
}
