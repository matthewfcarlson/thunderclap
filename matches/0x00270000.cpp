// Same code shape as 0x0026d270 (propagated; names are from that function)
class IMemoryPool_270000 {
  public:
    virtual void v0();
};
class IB_270000 {
  public:
    void helper();
};
class MemoryPool_270000 : public IMemoryPool_270000, public IB_270000 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
void MemoryPool_270000::vfunc_1() {
    IB_270000::helper();
}
