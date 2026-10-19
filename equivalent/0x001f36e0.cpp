// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001f36e0 @ 0x001f36e0
struct ThisCall_0027af60 {
    void FUN_0027af60(int, int);
};
extern "C" int __cdecl FUN_002673a0(int, int);
struct Object {
    char pad[8];
    int field8;
    int fieldC;
    int field10;
    int field14;
    unsigned char field18;
    void FUN_001f36e0();
};
void Object::FUN_001f36e0() {
    ((ThisCall_0027af60*)(this))->FUN_0027af60(0, 0);
    field8 = 0;
    fieldC = FUN_002673a0(0, 0);
    field10 = 999;
    field14 = 0;
    field18 = 0;
}