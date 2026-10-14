// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ca540 @ 0x001ca540
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
struct Name {
    int lo;
    int hi;
    ~Name() throw();
};

struct Request {
    int size;               // 0x00
    int kind;               // 0x04
    int f08;
    int f0c;
    int value;              // 0x10
    int f14;
    Name first;             // 0x18
    Name second;            // 0x20
    Request* Init(Name a, Name b, int v);
};

Request* Request::Init(Name a, Name b, int v)
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
    first = a;
    second = b;
    size = 0x28;
    kind = 0x13;
    value = v;
    return this;
}
