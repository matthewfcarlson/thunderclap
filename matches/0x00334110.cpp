// Same code shape as 0x0026d270 (propagated; names are from that function)
class IA {
  public:
    virtual void v0();
};
class IB_334110 {
  public:
    void helper();
};
class RenderStrategyBink_334110 : public IA, public IB_334110 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
void RenderStrategyBink_334110::vfunc_1() {
    IB_334110::helper();
}
