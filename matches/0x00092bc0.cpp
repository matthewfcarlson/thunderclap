class X {
  public:
    char pad[0x18];
    int value;
};
class C {
  public:
    X* items[1];
    int f(int index);
};
int C::f(int index) {
    return items[index]->value;
}