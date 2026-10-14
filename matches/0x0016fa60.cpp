class X {
  public:
    char pad[12];
    int m12;
    char Set(int v);
};

char X::Set(int v) {
    m12 = v;
    return 1;
}
