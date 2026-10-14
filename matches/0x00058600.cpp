extern "C" char DAT_003f7274[];
typedef unsigned int U_58600;
extern void* __cdecl alloc(unsigned int);
struct CPropActorStateCondition {
    virtual void v0();
    U_58600 x[4];
    void setup(int);
};
struct Factory_58600 {
    void* v0();
    void* v1();
    void* v2();
    void* v3();
    void* v4();
    void* v5();
};
void* Factory_58600::v5() {
    CPropActorStateCondition* p = (CPropActorStateCondition*)alloc(0x14);
    if (p) {
        p->setup(0);
        *(U_58600*)p = ((int)DAT_003f7274);
        *(U_58600*)((char*)p + 0xc) = 2;
        *(U_58600*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}