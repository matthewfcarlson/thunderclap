class X {
  public:
    char p14[0x14];
    int m14;
    char Set(int v);
};

char X::Set(int v) {
    m14 = v;
    return 1;
}
