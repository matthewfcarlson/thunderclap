// Same code shape as 0x0026d270 (propagated; names are from that function)
class IA {
  public:
    virtual void v0();
};
class IB {
  public:
    void helper();
};
class MemoryTwoWayAllocator : public IA, public IB {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
void MemoryTwoWayAllocator::vfunc_1() {
    IB::helper();
}
