class X {
  public:
    char Set(int x);
    char pad[12];
    int m;
};

char X::Set(int x) {
    m = x;
    return 1;
}