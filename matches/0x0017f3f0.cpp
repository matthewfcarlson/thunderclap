class Obj {
  public:
    char pad[0x24];
    unsigned char val;
    unsigned char Fn(unsigned char a);
};

unsigned char Obj::Fn(unsigned char a) {
    val = a;
    return 1;
}
