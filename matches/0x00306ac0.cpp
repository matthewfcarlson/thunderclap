extern void* DAT_00431b74[];
extern void* DAT_003f6098[];
void FUN_0008d330(void*) throw();
void FUN_0008d340(void*) throw();
class Ref_306ac0 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Vec_306ac0 {
    Ref_306ac0** b;
    Ref_306ac0** e;
};
class CollisionVolume_306ac0 {
  public:
    void* vptr;
    char pad[0x14 - 4];
    Vec_306ac0* v;
    ~CollisionVolume_306ac0() throw();
};
CollisionVolume_306ac0::~CollisionVolume_306ac0() throw() {
    vptr = DAT_00431b74;
    if (v) {
        for (unsigned i = 0; i < (unsigned)(v->e - v->b); i++)
            v->b[i]->Release();
        v->e = v->b;
        Vec_306ac0* p = v;
        if (p) {
            p->e = p->b;
            if (p->b)
                FUN_0008d340(p->b);
            FUN_0008d330(p);
        }
    }
    vptr = DAT_003f6098;
}
