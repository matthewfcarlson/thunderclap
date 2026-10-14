class Obj_5d740 {
  public:
    char Set(int x);
    char pad[0x24];
    int m24;
};

char Obj_5d740::Set(int x) {
    m24 = x;
    return 1;
}
