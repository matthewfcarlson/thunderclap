extern void* g_vt_1616c0[];

class RefObj_1616c0 {
  public:
    virtual ~RefObj_1616c0();
    virtual void Release();
};

void __cdecl DeleteObj(void*);

struct ClimbLocomotionAction {
    void* mVptr;
    char pad[0x18];
    RefObj_1616c0* m1c;
    RefObj_1616c0* m20;
    RefObj_1616c0* m24;
    void BaseDtor();
    ClimbLocomotionAction* vfunc_2(unsigned char flags);
};

ClimbLocomotionAction* ClimbLocomotionAction::vfunc_2(unsigned char flags) {
    volatile ClimbLocomotionAction* v = this;
    RefObj_1616c0* p;
    v->mVptr = g_vt_1616c0;
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
