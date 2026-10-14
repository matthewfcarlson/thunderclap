// Same code shape as 0x002226e0 (propagated; names are from that function)
class Inner_262fc0 {
  public:
    void call();
};
class Obj_262fc0 {
  public:
    char pad[0x10];
    void target();
};
void Obj_262fc0::target() {
    ((Inner_262fc0*)((char*)this + 0x10))->call();
}