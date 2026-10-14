class Obj_11c000 {
  public:
    char pad[0x14];
    int m14;
    char Set(int v);
};

char Obj_11c000::Set(int v) {
    m14 = v;
    return 1;
}
