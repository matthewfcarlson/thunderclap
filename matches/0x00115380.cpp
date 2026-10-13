class X {
  public:
    char m[0x29];
    char m29;
    char Set(int a);
};

char X::Set(int a) {
    m29 = (char)a;
    return 1;
}
