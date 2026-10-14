class Obj_192800 {
  public:
    char pad[0x14];
    int m14;
    char Set(int x);
};

char Obj_192800::Set(int x) {
    m14 = x;
    return 1;
}
