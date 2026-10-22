// Same code shape as 0x0026d270 (propagated; names are from that function)
class IRefCount_26e340 {
  public:
    virtual void v0();
};
class IB_26e340 {
  public:
    void helper();
};
class ConsoleClient_26e340 : public IRefCount_26e340, public IB_26e340 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
void ConsoleClient_26e340::vfunc_1() {
    IB_26e340::helper();
}
