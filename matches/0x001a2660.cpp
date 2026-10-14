class Obj_1a2660 {
  public:
    char pad[0xb8];
    unsigned char field;
    char Set(unsigned char v);
};

char Obj_1a2660::Set(unsigned char v) {
    field = v;
    return 1;
}
