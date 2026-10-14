class Obj_1a23e0 {
  public:
    char pad[0x68];
    char m68;
    char Set(char v);
};

char Obj_1a23e0::Set(char v) {
    m68 = v;
    return 1;
}
