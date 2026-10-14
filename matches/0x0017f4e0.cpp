class C {
  public:
    char Set(int x);
    char pad[32];
    int m20;
};
char C::Set(int x) {
    m20 = x;
    return 1;
}
