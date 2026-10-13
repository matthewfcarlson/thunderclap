class X {
  public:
    char pad[16];
    int m10;
    char Set(int v);
};

char X::Set(int v) {
    m10 = v;
    return 1;
}
