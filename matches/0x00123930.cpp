class Obj_123930 {
  public:
    char pad[0xc];
    unsigned char value;
    char Set(unsigned char v);
};
char Obj_123930::Set(unsigned char v) {
    value = v;
    return 1;
}
