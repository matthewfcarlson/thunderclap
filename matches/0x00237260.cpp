class B_237260 {
  public:
    int x;
};
class A_237260 {
  public:
    char pad[0x18];
    B_237260 val;
    B_237260* GetPtr();
};
B_237260* A_237260::GetPtr() {
    return &val;
}