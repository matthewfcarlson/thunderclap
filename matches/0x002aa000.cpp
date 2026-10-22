extern char gVftable_2aa000[];
extern void __cdecl freefn(void*);
extern void __cdecl opdel(void*);
extern "C" void _ReadWriteBarrier();

class RefObj_2aa000 {
  public:
    virtual void f0();
    virtual void Release();
};

class ExpressionAnimationController_2aa000 {
  public:
    void BaseDtor();
};

class ExpressionAnimationController {
  public:
    ExpressionAnimationController* vfunc_2(int flag);
};

ExpressionAnimationController* ExpressionAnimationController::vfunc_2(int flag) {
    char* b = (char*)this;
    *(void**)b = (void*)&gVftable_2aa000;
    _ReadWriteBarrier();
    RefObj_2aa000* pA = *(RefObj_2aa000**)(b + 0x40);
    if (pA) {
        pA->Release();
        *(int*)(b + 0x40) = 0;
    }
    RefObj_2aa000* pB = *(RefObj_2aa000**)(b + 0x44);
    if (pB) {
        pB->Release();
        *(int*)(b + 0x44) = 0;
    }
    _ReadWriteBarrier();
    freefn(*(void**)(b + 0x4c));
    ((ExpressionAnimationController_2aa000*)this)->BaseDtor();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}
