class X {
  public:
    char Set(int a);
    char pad[0x1c];
    int m1c;
};
char X::Set(int a) {
    m1c = a;
    return 1;
}
