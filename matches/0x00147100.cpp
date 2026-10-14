class Obj_147100 {
  public:
    char pad[0x24];
    int m24;
    char Set(int x);
};

char Obj_147100::Set(int x) {
    m24 = x;
    return 1;
}
