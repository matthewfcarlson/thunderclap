class C {
  public:
    char pad[0x14];
    int m;
    char Set(int x);
};

char C::Set(int x) {
    m = x;
    return 1;
}
