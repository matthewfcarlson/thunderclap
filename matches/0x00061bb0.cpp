class X {
  public:
    char pad[0x28];
    int m;
    char Set(int);
};

char X::Set(int v) {
    m = v;
    return 1;
}
