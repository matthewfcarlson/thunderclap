// Same code shape as 0x002226e0 (propagated; names are from that function)
class Inner_2226f0 {
  public:
    void call(int);
};
class Obj_2226f0 {
  public:
    char pad[0x10];
    void target(int);
};
void Obj_2226f0::target(int a0) {
    ((Inner_2226f0*)((char*)this + 0x10))->call(a0);
}