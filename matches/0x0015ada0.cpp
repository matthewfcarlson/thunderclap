class C {
  public:
    char pad[0x14];
    int m14;
    char Set(int x);
};
char C::Set(int x) {
    m14 = x;
    return 1;
}