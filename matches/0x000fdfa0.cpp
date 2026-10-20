#include "compat/ptr.h"
class CActorGolem_fdfa0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void vfunc_4(int, int);
};
class CCharacterGolem : public CActorGolem_fdfa0 {
  public:
    char pad[0x124];
    unsigned char flag;
    virtual void x1();
    virtual int get();
    void vfunc_4(int, int);
};
void CCharacterGolem::vfunc_4(int a, int b) {
    CActorGolem_fdfa0::vfunc_4(a, b);
    if (flag) {
        hulk_intptr v = get();
        if (v) {
            int* p = (int*)(v + 0x1f58);
            if (p)
                *(int*)((char*)p + 0x118) = 0;
        }
    }
}