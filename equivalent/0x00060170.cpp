// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00060170 @ 0x00060170
extern "C" void* __cdecl memset(void*, int, unsigned int);

struct Sub {
    char data[8];
    void FUN_0027b040(int arg);
};

struct Object {
    char head[0x10c];
    int f10c, f110, f114, f118, f11c, f120, f124, f128, f12c, f130, f134, f138, f13c;
    Sub sub;
    char flag;
    void FUN_00060170();
};

void Object::FUN_00060170() {
    memset(this, 0, 0x10c);
    f114 = 0;
    f110 = 0;
    f10c = 0;
    f118 = 0;
    f124 = 0;
    f120 = 0;
    f11c = 0;
    f130 = 0;
    f12c = 0;
    f128 = 0;
    sub.FUN_0027b040(0);
    flag = 0;
    f13c = 0;
    f138 = 0;
    f134 = 0;
}
