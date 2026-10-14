class C {
  public:
    char pad[0x10];
    int m10;
    char f(int a);
};

char C::f(int a) {
    m10 = a;
    return 1;
}
