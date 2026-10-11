extern "C" char DAT_004318f4[];
struct Base {
    virtual void a();
    virtual void b();
};
void __cdecl release(void*);
class Obj {
  public:
    void cleanup(int);
};
class Sim {
  public:
    void* vptr;
    char p1[0x6c];
    Obj* m70;
    char p2[0x14];
    Base* m88;
    void* m8c;
    void tail();
    void run();
};
void Sim::run() {
    vptr = (void*)((int)DAT_004318f4);
    if (m8c)
        release((char*)m8c - 4);
    if (m70)
        m70->cleanup(0);
    if (m88) {
        m88->b();
        m88 = 0;
    }
    tail();
}