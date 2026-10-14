class C {
  public:
    char pad[0x90];
    int m90;
    char Set(int x);
};

char C::Set(int x) {
    m90 = x;
    return 1;
}