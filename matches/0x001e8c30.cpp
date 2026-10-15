// Same code shape as 0x001e86c0 (propagated; names are from that function)
class CSoundSequence {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int);
    int mRefCount;
};
void CSoundSequence::vfunc_1() {
    if (--mRefCount == 0)
        vfunc_2(1);
}