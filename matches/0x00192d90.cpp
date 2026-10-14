class Obj_192d90 {
  public:
    char pad[0xfd];
    unsigned char value;
    unsigned char Set(unsigned char v);
};
unsigned char Obj_192d90::Set(unsigned char v) {
    value = v;
    return 1;
}