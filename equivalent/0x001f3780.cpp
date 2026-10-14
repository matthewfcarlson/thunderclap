// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001f3780 @ 0x001f3780
// 0x001f3780: constructor that resets two names, an id and four unit-scale slots
struct Name {
    void FUN_0027af00();
    char data[8];
};

struct Slot {
    int a;
    int b;
    int pad08;
    char flag;
    char pad0d[11];
    float sx;
    float sy;
    float sz;
    int pad24;
};

class Holder {
public:
    Name name0;
    Name name1;
    char pad10[0x64];
    int id;
    int field_78;
    int pad7c;
    Slot slots[4];
    int field_120;
    Holder* FUN_001f3780();
};

Holder* Holder::FUN_001f3780()
{
    name0.FUN_0027af00();
    name1.FUN_0027af00();
    id = 99;
    field_78 = 0;
    for (int i = 0; i < 4; i++) {
        slots[i].a = 0;
        slots[i].b = 0;
        slots[i].flag = 0;
        slots[i].sx = 1.0f;
        slots[i].sy = 1.0f;
        slots[i].sz = 1.0f;
    }
    field_120 = 0;
    return this;
}
