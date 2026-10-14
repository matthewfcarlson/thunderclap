class Obj_5d780 {
  public:
    char pad[0x40];
    int m40;
    char Set(int v);
};

char Obj_5d780::Set(int v) {
    m40 = v;
    return 1;
}
