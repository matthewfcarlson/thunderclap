// STATUS: equivalent (tools/equiv.py level 3: 1647 inputs, branch coverage 2/2)
// FUN_0023b470 @ 0x0023b470
struct Name_23b470 {
    char d[8];
    void FUN_0027af00();
};

struct Entry_23b470 {
    char d[0x18];
    void FUN_0027af00();
};

class Source_23b470 {
public:
    virtual void v0();
};

namespace fight {
class ScriptReader {
public:
    ScriptReader(Source_23b470 *src, int b);
    virtual void v0();
    int f4;
    Source_23b470 *src;
    int b;
    int f10;
    int f14;
    char pad18[0x118 - 0x18];
    Name_23b470 n118;
    Name_23b470 n120;
    int f128;
    int f12c;
    Entry_23b470 entries[0x200];
    void FUN_0023a6b0();
};
}

fight::ScriptReader::ScriptReader(Source_23b470 *s, int bb)
{
    f4 = 0;
    b = bb;
    f10 = 0;
    n118.FUN_0027af00();
    n120.FUN_0027af00();
    f128 = 0;
    f12c = 0;
    for (int i = 0; i < 0x200; i++)
        entries[i].FUN_0027af00();
    f14 = -1;
    src = s;
    s->v0();
    FUN_0023a6b0();
}
