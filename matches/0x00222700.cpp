// Same code shape as 0x002226e0 (propagated; names are from that function)
class Inner_222700 {
  public:
    void call();
};
class Obj_222700 {
  public:
    char pad[0x10];
    void target();
};
void Obj_222700::target() {
    ((Inner_222700*)((char*)this + 0x10))->call();
}