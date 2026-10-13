class X {
  public:
    char pad[0x10];
    int m10;
    char Set(int a);
};

char X::Set(int a) {
    m10 = a;
    return 1;
}
