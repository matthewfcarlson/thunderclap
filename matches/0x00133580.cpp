class Obj_133580 {
    char pad[0x24];
    char m24;
    unsigned char m25;

  public:
    char Set(unsigned char v);
};

char Obj_133580::Set(unsigned char v) {
    m24 = v;
    return 1;
}
