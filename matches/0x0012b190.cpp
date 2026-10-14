class A_12b190 {
  public:
    char pad[0xc];
    unsigned char value;
    bool Set(unsigned char x);
};
bool A_12b190::Set(unsigned char x) {
    value = x;
    return true;
}
