class Sub_13890 {
  public:
    void G();
};
class Obj_13890 {
  public:
    char pad[0x18];
    void F();
};
void Obj_13890::F() {
    ((Sub_13890*)((char*)this + 0x18))->G();
}