class Inner_2226e0 {
  public:
    void call();
};
class Obj_2226e0 {
  public:
    char pad[0x10];
    void target();
};
void Obj_2226e0::target() {
    ((Inner_2226e0*)((char*)this + 0x10))->call();
}