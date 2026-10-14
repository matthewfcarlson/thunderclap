class Obj_10c450 {
  public:
    char Pad[0x14];
    char m14;
    char Set(char x);
};

char Obj_10c450::Set(char x) {
    m14 = x;
    return 1;
}
