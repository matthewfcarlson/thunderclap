class Obj_10c3f0 {
  public:
    char pad[0x20];
    char m20;
    char Set(char x);
};

char Obj_10c3f0::Set(char x) {
    m20 = x;
    return 1;
}
