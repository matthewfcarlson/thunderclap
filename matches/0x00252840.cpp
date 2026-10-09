class SeqAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(void*);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
class SeqActionVarVolume : public SeqAction {
  public:
    int pad4;
    int mValue;
    int mState;
    void vfunc_1(void* p);
};
void SeqActionVarVolume::vfunc_1(void* p) {
    *(int*)((char*)*(int*)((char*)p + 4) + 0x18) = mValue + 8;
    mState = 0;
}