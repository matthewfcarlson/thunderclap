// Same code shape as 0x00201c00 (propagated; names are from that function)
struct Inner_201de0 {
    void Init(int);
};
class Thing_201de0 {
  public:
    char pad[0x18];
    int value;
    char pad2[4];
    Inner_201de0 inner;
    void f();
};
void Thing_201de0::f() {
    value = 0xc61c4000;
    inner.Init(0);
    ((char*)this)[0x28] = 0;
}