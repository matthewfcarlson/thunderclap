class C {
  public:
    char pad[0x5a4];
    char a[0x400];
    bool f(int i);
};
bool C::f(int i) {
    if (i < 0)
        return false;
    if (i >= 0x400)
        return false;
    return a[i] == 2;
}
