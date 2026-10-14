class Obj {
  public:
    char pad[0x44];
    char m;
    unsigned char Fn(unsigned char a);
};

unsigned char Obj::Fn(unsigned char a) {
    m = a;
    return 1;
}
