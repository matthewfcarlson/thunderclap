class Obj_10c170 {
  public:
    char pad[0x14];
    unsigned m14;
    unsigned char Set(unsigned v);
};

unsigned char Obj_10c170::Set(unsigned v) {
    m14 = v;
    return 1;
}
