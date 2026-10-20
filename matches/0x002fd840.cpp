#include "compat/ptr.h"
extern "C" char DAT_004318f4[];
struct Base_2fd840 {
    virtual void a();
    virtual void b();
};
void __cdecl release(void*);
class Obj_2fd840 {
  public:
    void cleanup(int);
};
class Sim_2fd840 {
  public:
    void* vptr;
    char p1[0x6c];
    Obj_2fd840* m70;
    char p2[0x14];
    Base_2fd840* m88;
    void* m8c;
    void tail();
    void run();
};
void Sim_2fd840::run() {
    vptr = (void*)((hulk_intptr)DAT_004318f4);
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