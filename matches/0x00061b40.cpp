class X {
  public:
    char pad[0xc];
    int m;
    char Set(int a);
};

char X::Set(int a) {
    m = a;
    return 1;
}
