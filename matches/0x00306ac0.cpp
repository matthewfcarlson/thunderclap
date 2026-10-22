extern void* g_vt_306ac0[];
extern void* g_vt2[];
void Free(void*) throw();
void Free2(void*) throw();
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
    vptr = g_vt_306ac0;
    if (v) {
        for (unsigned i = 0; i < (unsigned)(v->e - v->b); i++)
            v->b[i]->Release();
        v->e = v->b;
        Vec_306ac0* p = v;
        if (p) {
            p->e = p->b;
            if (p->b)
                Free2(p->b);
            Free(p);
        }
    }
    vptr = g_vt2;
}
