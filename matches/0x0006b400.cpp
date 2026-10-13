class X {
  public:
    char Set(int v);
    char pad[0x54];
    int m54;
};

char X::Set(int v) {
    m54 = v;
    return 1;
}
