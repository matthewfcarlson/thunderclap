class Obj_193220 {
  public:
    char pad[0x77];
    char flag;
    unsigned char Set(unsigned char v);
};

unsigned char Obj_193220::Set(unsigned char v) {
    flag = v;
    return 1;
}
