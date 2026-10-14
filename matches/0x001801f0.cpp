class X {
  public:
    char Set(int v);
    char pad[0x14];
    int m14;
};
char X::Set(int v) {
    m14 = v;
    return 1;
}