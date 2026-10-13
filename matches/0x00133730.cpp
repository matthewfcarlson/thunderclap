class X {
  public:
    char Set(int a);
    char pad[0x24];
    int m24;
};

char X::Set(int a) {
    m24 = a;
    return 1;
}
