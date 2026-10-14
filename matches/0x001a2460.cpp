class O {
  public:
    char m[0x78];
    char f(char v);
};
char O::f(char v) {
    m[0x78] = v;
    return 1;
}
