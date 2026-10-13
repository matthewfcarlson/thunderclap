class X {
  public:
    char pad[0x28];
    char m28;
    char Fn(unsigned char a);
};
char X::Fn(unsigned char a) {
    m28 = a;
    return 1;
}
