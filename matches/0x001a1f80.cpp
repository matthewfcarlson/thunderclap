class C {
  public:
    char pad[12];
    int m;
    char Fn(int x);
};

char C::Fn(int x) {
    m = x;
    return 1;
}
