extern "C" void* __cdecl thunk_FUN_0008d690(unsigned int);
class Thing {
  public:
    virtual void A();
    virtual void B();
    char pad[8];
    unsigned char ready;
};
class Factory {
  public:
    Thing* Make(int, int, int);
};
class Manager {
  public:
    int Run(const char*, Thing*, int);
};
extern "C" char gFlag;
extern "C" Factory* gMaker;
extern "C" Manager* gManager;
char gFlag;
Factory* gMaker;
Manager* gManager;
int __stdcall FUN_00024400(int param, char skip) {
    Thing* p;
    int result;
    if (skip && !gFlag)
        return 0;
    Factory* f = (Factory*)thunk_FUN_0008d690(0x48);
    if (f)
        p = f->Make(param, 0, 1);
    else
        p = 0;
    p->A();
    if (!p->ready) {
        p->B();
        return 0;
    }
    result = gManager->Run("fig0", p, 0);
    p->B();
    return result;
}