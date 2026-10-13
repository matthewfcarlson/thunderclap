class Obj {
    char pad[0x1c];

  public:
    unsigned char b;
    unsigned char Method(unsigned char v);
};

unsigned char Obj::Method(unsigned char v) {
    b = v;
    return 1;
}