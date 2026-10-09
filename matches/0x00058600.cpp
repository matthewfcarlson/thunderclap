typedef unsigned int U;
extern void* __cdecl alloc(unsigned int);
struct CPropActorStateCondition {
    virtual void v0();
    U x[4];
    void setup(int);
};
struct Factory {
    void* v0();
    void* v1();
    void* v2();
    void* v3();
    void* v4();
    void* v5();
};
void* Factory::v5() {
    CPropActorStateCondition* p = (CPropActorStateCondition*)alloc(0x14);
    if (p) {
        p->setup(0);
        *(U*)p = 0x3f7274;
        *(U*)((char*)p + 0xc) = 2;
        *(U*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}