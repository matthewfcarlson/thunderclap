// Same code shape as 0x002226e0 (propagated; names are from that function)
class Inner_2777b0 {
  public:
    void call();
};
class Obj_2777b0 {
  public:
    char pad[0x10];
    void target();
};
void Obj_2777b0::target() {
    ((Inner_2777b0*)((char*)this + 0x10))->call();
}