class C {
  public:
    int f(int index);
};
int C::f(int index) {
    return ((int*)this)[index] + 0x10;
}