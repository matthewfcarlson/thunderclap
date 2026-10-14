class Obj_67f80 {
    char pad[0x30];
    unsigned char m;

  public:
    unsigned char Set(unsigned char v);
};

unsigned char Obj_67f80::Set(unsigned char v) {
    m = v;
    return 1;
}
