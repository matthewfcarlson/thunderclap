class Obj_18cc60 {
  public:
    char pad[0x24];
    char m24;
    char Set(char v);
};

char Obj_18cc60::Set(char v) {
    m24 = v;
    return 1;
}
