// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ca3d0 @ 0x001ca3d0
struct Packet {
    unsigned int kind;
    unsigned int subtype;
    unsigned int unused08;
    unsigned int unused0c;
    unsigned int value10;
    unsigned int unused14;
    unsigned int value18;
    unsigned int value1c;
    unsigned int value20;
    unsigned int value24;
    unsigned int value28;
    unsigned int unused2c;
    Packet* FUN_001ca3d0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f);
};
struct Arg { void FUN_0027af50(); };
Packet* Packet::FUN_001ca3d0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f)
{
    unsigned int* words = (unsigned int*)this;
    for (int i = 0; i < 12; ++i) words[i] = 0;
    value1c = b;
    value18 = a;
    value20 = c;
    value28 = f;
    kind = 0x30;
    subtype = 0x12;
    value24 = d;
    value10 = e;
    ((Arg*)&a)->FUN_0027af50();
    ((Arg*)&c)->FUN_0027af50();
    return this;
}