class SeqCommand {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class SeqCommandLogicRepeat : public SeqCommand {
  public:
    virtual void vfunc_0();
    virtual SeqCommandLogicRepeat* vfunc_1(int);
};
extern int SeqCommand_vftable;
extern void __cdecl FUN_00247550(void*, void*);
SeqCommandLogicRepeat* SeqCommandLogicRepeat::vfunc_1(int x) {
    *(int*)this = (int)&SeqCommand_vftable;
    if (x & 1)
        FUN_00247550((void*)0x4e7360, this);
    return this;
}