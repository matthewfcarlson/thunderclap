class Obj_1936d0 {
  public:
    char pad[0x124];
    int value;
    char Set(int v);
};

char Obj_1936d0::Set(int v) {
    value = v;
    return 1;
}
