class IMemoryTwoWayAllocator_26d270 {
  public:
    virtual void v0();
};
class IB_26d270 {
  public:
    void helper();
};
class MemoryTwoWayAllocator : public IMemoryTwoWayAllocator_26d270, public IB_26d270 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
void MemoryTwoWayAllocator::vfunc_1() {
    IB_26d270::helper();
}
