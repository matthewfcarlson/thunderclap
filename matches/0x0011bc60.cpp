class X {
  public:
    char pad[0x20];
    int m;
    char Set(int v);
};

char X::Set(int v) {
    m = v;
    return 1;
}
