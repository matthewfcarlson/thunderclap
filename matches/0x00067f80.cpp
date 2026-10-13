class Obj {
    char pad[0x30];
    unsigned char m;

  public:
    unsigned char Set(unsigned char v);
};

unsigned char Obj::Set(unsigned char v) {
    m = v;
    return 1;
}
