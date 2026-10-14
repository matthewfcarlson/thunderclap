class Obj_139db0 {
  public:
    char pad[0x20];
    int m20;
    char Set(int v);
};

char Obj_139db0::Set(int v) {
    m20 = v;
    return 1;
}
