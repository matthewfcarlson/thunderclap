extern "C" char DAT_0041c3ac[];
extern "C" char DAT_0041c420[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void FUN_002347b0(void*, void**, int);
extern "C" int g_count;
extern "C" void* g_slot;
class Base {
  public:
    virtual void V0();
};
class ParamScript : public Base {
  public:
    void Init(const char*);
    char pad[8];
    void* mFn;
};
void FUN_001a1b00() {
    void* tmp;
    if (g_count == 0) {
        ParamScript* p = (ParamScript*)FUN_0008d690(0x18);
        if (p) {
            p->Init((const char*)((int)DAT_0041c420));
            *(unsigned int*)p = ((int)DAT_0041c3ac);
            *(unsigned int*)((char*)p + 0x10) = 0x1a1350;
            tmp = p;
        } else
            tmp = 0;
        FUN_002347b0(&g_slot, &tmp, 1);
    }
    ++g_count;
}