class Sub {
  public:
    void G();
};
class Obj {
  public:
    char pad[0x18];
    void F();
};
void Obj::F() {
    ((Sub*)((char*)this + 0x18))->G();
}