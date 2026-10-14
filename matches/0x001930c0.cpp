class Obj {
  public:
    char pad[0x58];
    unsigned char field;
    unsigned char Fn(unsigned char x);
};
unsigned char Obj::Fn(unsigned char x) {
    field = x;
    return 1;
}
