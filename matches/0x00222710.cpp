// Same code shape as 0x002226e0 (propagated; names are from that function)
class Inner_222710 {
  public:
    void call();
};
class Obj_222710 {
  public:
    char pad[0x10];
    void target();
};
void Obj_222710::target() {
    ((Inner_222710*)((char*)this + 0x10))->call();
}