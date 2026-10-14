class C_192aa0 {
  public:
    char pad[0x90];
    int m90;
    char Set(int x);
};

char C_192aa0::Set(int x) {
    m90 = x;
    return 1;
}