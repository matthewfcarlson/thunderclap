class X {
  public:
    char Set(int v);
    char pad[0x37];
    int m38;
};

char X::Set(int v) {
    m38 = v;
    return 1;
}
