class Sub_13890 {
  public:
    void G(int);
};
class Obj_13890 {
  public:
    char pad[0x18];
    void F(int);
};
void Obj_13890::F(int a0) {
    ((Sub_13890*)((char*)this + 0x18))->G(a0);
}