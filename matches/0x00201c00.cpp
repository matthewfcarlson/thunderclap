struct Inner_201c00 {
    void Init(int);
};
class Thing_201c00 {
  public:
    char pad[0x18];
    int value;
    char pad2[4];
    Inner_201c00 inner;
    void f();
};
void Thing_201c00::f() {
    value = 0xc61c4000;
    inner.Init(0);
    ((char*)this)[0x28] = 0;
}