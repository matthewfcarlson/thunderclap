class X {
  public:
    char Set(int a);
    char m[0x14];
    int value;
};

char X::Set(int a) {
    value = a;
    return 1;
}
