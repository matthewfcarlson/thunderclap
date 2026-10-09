extern int SeqActionVftable;
extern int gBss;
extern void __cdecl FUN_00247550(void*, void*);
class SeqAction {
  public:
    int* vptr;
};
class SeqActionVarPitch : public SeqAction {
  public:
    SeqAction* vfunc_0(int);
};
SeqAction* SeqActionVarPitch::vfunc_0(int flag) {
    SeqAction* self = this;
    vptr = (int*)0x4298fc;
    if (flag & 1)
        FUN_00247550(&gBss, self);
    return self;
}