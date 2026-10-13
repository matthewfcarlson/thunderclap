class B {
  public:
    int x;
};
class A {
  public:
    char pad[0x18];
    B val;
    B* GetPtr();
};
B* A::GetPtr() {
    return &val;
}