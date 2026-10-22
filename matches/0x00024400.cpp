extern "C" void* __cdecl thunk_FUN_0008d690(unsigned int);
class Thing_24400 {
  public:
    virtual void A();
    virtual void B();
    char pad[8];
    unsigned char ready;
};
class LoadStream_24400 {
  public:
    Thing_24400* Make(int, int, int);
};
class Manager_24400 {
  public:
    int Run(const char*, Thing_24400*, int);
};
extern "C" char gFlag_24400;
extern "C" LoadStream_24400* gMaker;
extern "C" Manager_24400* gManager_24400;
char gFlag_24400;
LoadStream_24400* gMaker;
Manager_24400* gManager_24400;
int __stdcall FUN_00024400(int param, char skip) {
    Thing_24400* p;
    int result;
    if (skip && !gFlag_24400)
        return 0;
    LoadStream_24400* f = (LoadStream_24400*)thunk_FUN_0008d690(0x48);
    if (f)
        p = f->Make(param, 0, 1);
    else
        p = 0;
    p->A();
    if (!p->ready) {
        p->B();
        return 0;
    }
    result = gManager_24400->Run("fig0", p, 0);
    p->B();
    return result;
}