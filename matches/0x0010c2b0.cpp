class C {
    char pad[0x14];
    int m14;

  public:
    char Set(int x);
};
char C::Set(int x) {
    m14 = x;
    return 1;
}