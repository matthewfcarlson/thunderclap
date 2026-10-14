class C {
    char pad[0x14];
    int m;

  public:
    char Fn(int x);
};

char C::Fn(int x) {
    m = x;
    return 1;
}
