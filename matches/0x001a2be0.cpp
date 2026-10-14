class Obj_1a2be0 {
  public:
    char pad[0x168];
    char m;
    char Set(unsigned char v);
};

char Obj_1a2be0::Set(unsigned char v) {
    m = v;
    return 1;
}
