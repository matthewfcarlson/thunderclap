class X {
  public:
    char Pad[0x10];
    int m10;
    char F(int a);
};

char X::F(int a) {
    m10 = a;
    return 1;
}