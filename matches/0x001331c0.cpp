class Obj_1331c0 {
  public:
    char pad[0x28];
    int m28;
    char Set(int v);
};

char Obj_1331c0::Set(int v) {
    m28 = v;
    return 1;
}