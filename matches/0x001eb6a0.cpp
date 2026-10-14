class B_1eb6a0 {
  public:
    void G();
};
class A_1eb6a0 {
  public:
    virtual void F();
};
void A_1eb6a0::F() {
    ((B_1eb6a0*)*(void**)*(void**)this)->G();
}