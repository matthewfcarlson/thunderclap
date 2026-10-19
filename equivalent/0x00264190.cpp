// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00264190 @ 0x00264190
namespace content {
struct LoadStream {
    virtual void hulk_slot_FUN_00263f50(); void FUN_00263f50();
    int field04;
    char pad08[4];
    unsigned char flag0c;
    char pad0d;
    unsigned char flag0e;
    char pad0f;
    int field10, field14, field18, field1c;
    char pad20[8];
    int field28, field2c, field30, field34, field38;
    LoadStream(int a, int b);
};
LoadStream::LoadStream(int a, int b) {
    field04 = 0;
    FUN_00263f50();
    field28 = a;
    field1c = 0;
    field2c = 0;
    field18 = 0;
    field14 = 0;
    field34 = 0;
    field10 = b;
    field30 = b;
    field38 = b;
    flag0c = 1;
    flag0e = 1;
}
}