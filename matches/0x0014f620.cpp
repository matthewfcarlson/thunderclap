// Same code shape as 0x00147d20 (propagated; names are from that function)
class Base_14f620 {
  public:
    void run();
};
class GrappleHitReactionAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void vfunc_4();
    virtual void f5();
    char pad[0x20];
};
void GrappleHitReactionAction::vfunc_4() {
    ((Base_14f620*)((char*)this + 0x24))->run();
}