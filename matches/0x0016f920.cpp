class C {
  public:
    char F(int v);
    char pad[0x1c];
    int m;
};

char C::F(int v) {
    m = v;
    return 1;
}
