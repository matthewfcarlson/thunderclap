// Same code shape as 0x0026d270 (propagated; names are from that function)
class IA {
  public:
    virtual void v0();
};
class IB_333f80 {
  public:
    void helper();
};
class PlayerBink_333f80 : public IA, public IB_333f80 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
void PlayerBink_333f80::vfunc_1() {
    IB_333f80::helper();
}
