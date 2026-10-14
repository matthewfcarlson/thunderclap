// Same code shape as 0x001eb6a0 (propagated; names are from that function)
class B_1eb6b0 {
  public:
    void G();
};
class A_1eb6b0 {
  public:
    virtual void F();
};
void A_1eb6b0::F() {
    ((B_1eb6b0*)*(void**)*(void**)this)->G();
}