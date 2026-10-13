class C {
  public:
    char pad[12];
    int m;
    unsigned char f(int x);
};

unsigned char C::f(int x) {
    m = x;
    return 1;
}
