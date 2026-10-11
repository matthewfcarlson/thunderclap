extern "C" char DAT_003fbfe0[];
class Track {
  public:
    virtual void v();
    Track();
    char pad[8];
    int a;
    int b;
    int c;
};
extern "C" void* __cdecl operator_new(unsigned int);
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* f5();
};
void* Factory::f5() {
    Track* p = (Track*)operator_new(0x18);
    if (p) {
        p->Track::Track();
        *(unsigned int*)p = ((int)DAT_003fbfe0);
        p->a = 0;
        p->b = (int)0xbf800000;
        p->c = 0;
        *(int*)((char*)p + 8) = 1;
        return p;
    }
    return 0;
}