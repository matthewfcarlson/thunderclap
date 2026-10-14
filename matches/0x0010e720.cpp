extern "C" char DAT_0040d9a4[];
struct Sub_10e720 {
    void init();
};
class AIFightNodeCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual AIFightNodeCondition* vfunc_5(unsigned char param);
    virtual void v6();
    void baseInit();
    char pad[0x0c];
};
extern void thunk_FUN_00267090(AIFightNodeCondition*);
AIFightNodeCondition* AIFightNodeCondition::vfunc_5(unsigned char param) {
    *(void**)this = (void*)((int)DAT_0040d9a4);
    ((Sub_10e720*)((char*)this + 0xc))->init();
    baseInit();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
