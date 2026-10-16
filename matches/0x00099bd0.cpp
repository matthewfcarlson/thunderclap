class Child {
  public:
    void Func(int);
};
class Obj {
  public:
    char pad[0xb8];
    Child* child;
    void Func(int);
};
void Obj::Func(int x) {
    if (child)
        child->Func(x);
}