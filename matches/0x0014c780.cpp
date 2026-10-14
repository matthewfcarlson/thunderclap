class Obj_14c780 {
  public:
    char pad[0x10];
    int value;
    char Set(int x);
};

char Obj_14c780::Set(int x) {
    value = x;
    return 1;
}
