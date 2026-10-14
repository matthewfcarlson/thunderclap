class Obj_12e170 {
  public:
    char Set(char c);
    char pad[0x24];
    char m24;
};

char Obj_12e170::Set(char c) {
    m24 = c;
    return 1;
}
