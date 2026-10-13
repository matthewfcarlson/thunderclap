class C {
  public:
    char pad[0x10];
    int m10;
    bool F(int a);
};
bool C::F(int a) {
    m10 = a;
    return true;
}
