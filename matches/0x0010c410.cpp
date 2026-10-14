class Obj_10c410 {
  public:
    char pad[0x21];
    char m;
    unsigned char Fn(unsigned char x);
};

unsigned char Obj_10c410::Fn(unsigned char x) {
    m = x;
    return 1;
}
