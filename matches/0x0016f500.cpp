class Obj_16f500 {
  public:
    char pad[0x44];
    char m;
    unsigned char Fn(unsigned char a);
};

unsigned char Obj_16f500::Fn(unsigned char a) {
    m = a;
    return 1;
}
