class X {
  public:
    char Set(int a);
    char mPad[0x14];
    int m14;
};
char X::Set(int a) {
    m14 = a;
    return 1;
}
