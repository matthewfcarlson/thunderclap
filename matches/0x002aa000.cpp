extern char gVftable[];
extern void __cdecl freefn(void*);
extern void __cdecl opdel(void*);
extern "C" void _ReadWriteBarrier();

class RefObj {
  public:
    virtual void f0();
    virtual void Release();
};

class Base {
  public:
    void BaseDtor();
};

class ExpressionAnimationController {
  public:
    ExpressionAnimationController* vfunc_2(int flag);
};

ExpressionAnimationController* ExpressionAnimationController::vfunc_2(int flag) {
    char* b = (char*)this;
    *(void**)b = (void*)&gVftable;
    _ReadWriteBarrier();
    RefObj* pA = *(RefObj**)(b + 0x40);
    if (pA) {
        pA->Release();
        *(int*)(b + 0x40) = 0;
    }
    RefObj* pB = *(RefObj**)(b + 0x44);
    if (pB) {
        pB->Release();
        *(int*)(b + 0x44) = 0;
    }
    _ReadWriteBarrier();
    freefn(*(void**)(b + 0x4c));
    ((Base*)this)->BaseDtor();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}
