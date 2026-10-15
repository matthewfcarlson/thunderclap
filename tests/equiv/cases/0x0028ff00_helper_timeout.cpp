// STATUS: equivalent (tools/equiv.py level 3: 19 inputs, branch coverage 10/10)
// FUN_0028ff00 @ 0x0028ff00
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);
extern "C" void *memset(void *dst, int c, unsigned int n);

struct Name_28ff00 {
    char data[8];
    void FUN_0027b040(const char *s);
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void e0();
    char pad4[4];
    Name_28ff00 name;
    void FUN_0027b070();
    Entity() throw() { FUN_0027b070(); }
};

namespace prop {
class StateData : public Entity {
public:
    virtual void x1();
    virtual void x2();
    virtual void x3();
    char *base;
    int count4;
    char *area4;
    int count5;
    char *area5;
    int count1;
    char *area1;
    int count2;
    char *area2;
    int count3;
    char *area3;
    int count6;
    char *area6;
    int count7;
    char *area7;
    int f4c;
    char *buffer;
    StateData(int n1, int n2, int n3, int n4, int n5, int n6, int n7) throw();
};
}
}

static int Align4(int bytes)
{
    return (bytes + 3) & ~3;
}

pure3d::prop::StateData::StateData(int n1, int n2, int n3, int n4, int n5, int n6, int n7) throw()
{
    count4 = n4;
    int size4 = Align4(n4 * 16);
    count6 = n6;
    count7 = n7;
    count5 = n5;
    count3 = n3;
    count2 = n2;
    count1 = n1;
    base = 0;
    area4 = 0;
    area5 = 0;
    area1 = 0;
    area2 = 0;
    area3 = 0;
    area6 = 0;
    area7 = 0;
    f4c = 0;
    buffer = 0;
    int size6 = Align4(n6 * 16);
    int size5 = Align4(n5 * 32);
    int size3 = Align4(n3 * 16);
    int size1 = Align4(n1 * 16);
    int size7 = Align4(n7 * 0x58);
    int size2 = Align4(n2 * 48);
    int total = size6 + size5 + size4 + size3 + size7 + size1 + size2 + 0xc;
    buffer = (char *)FUN_0008d6d0(total);
    memset(buffer, 0, total);
    char *b = buffer;
    area4 = b + 0xc;
    int off = size4 + 0xc;
    area5 = b + off;
    off += size5;
    base = b;
    if (n1 > 0) {
        area1 = b + off;
        off += size1;
    }
    if (n2 > 0) {
        area2 = b + off;
        off += size2;
    }
    if (n3 > 0) {
        area3 = b + off;
        off += size3;
    }
    if (n7 > 0) {
        area7 = b + off;
        off += size7;
    }
    if (n6 > 0) {
        area6 = b + off;
    }
}
