// Same code shape as 0x00018b30 (propagated; names are from that function)
class IRefCount {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};
class CSoundSequence : public IRefCount {
  public:
    virtual void vfunc_0();
};
void CSoundSequence::vfunc_0() {
    ++mRefCount;
}
