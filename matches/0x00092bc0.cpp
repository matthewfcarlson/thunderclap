class X_92bc0 {
  public:
    char pad[0x18];
    int value;
};
class C_92bc0 {
  public:
    X_92bc0* items[1];
    int f(int index);
};
int C_92bc0::f(int index) {
    return items[index]->value;
}