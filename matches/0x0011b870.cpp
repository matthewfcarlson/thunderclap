class C {
  public:
    char m[0x19];
    char f(char c);
};

char C::f(char c) {
    m[0x19] = c;
    return 1;
}
