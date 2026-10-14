class Obj {
  public:
    char pad[0x158];
    char value;
    unsigned char Fn(unsigned char x);
};
unsigned char Obj::Fn(unsigned char x) {
    value = x;
    return 1;
}
