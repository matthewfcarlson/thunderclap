extern void* g_vt[];

class RefObj {
  public:
    virtual ~RefObj();
    virtual void Release();
};

void __cdecl DeleteObj(void*);

struct ClimbLocomotionAction {
    void* mVptr;
    char pad[0x18];
    RefObj* m1c;
    RefObj* m20;
    RefObj* m24;
    void BaseDtor();
    ClimbLocomotionAction* vfunc_2(unsigned char flags);
};

ClimbLocomotionAction* ClimbLocomotionAction::vfunc_2(unsigned char flags) {
    volatile ClimbLocomotionAction* v = this;
    RefObj* p;
    v->mVptr = g_vt;
    p = v->m24;
    if (p) {
        p->Release();
        v->m24 = 0;
    }
    p = v->m20;
    if (p) {
        p->Release();
        v->m20 = 0;
    }
    p = v->m1c;
    if (p) {
        p->Release();
        v->m1c = 0;
    }
    BaseDtor();
    if (flags & 1)
        DeleteObj(this);
    return this;
}
