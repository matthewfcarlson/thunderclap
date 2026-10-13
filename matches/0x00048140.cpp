class X {
  public:
    char pad[0x14];
    char mVal;
    char Fn(char a);
};

char X::Fn(char a) {
    mVal = a;
    return 1;
}
