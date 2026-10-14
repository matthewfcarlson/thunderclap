class X {
  public:
    char Set(int a);
    char pad[12];
    int m;
};
char X::Set(int a) {
    m = a;
    return 1;
}