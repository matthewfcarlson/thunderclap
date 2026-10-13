class Obj {
  public:
    char pad[0x21];
    char m;
    unsigned char Fn(unsigned char x);
};

unsigned char Obj::Fn(unsigned char x) {
    m = x;
    return 1;
}
