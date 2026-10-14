class Obj_11c1a0 {
  public:
    char pad[0x54];
    int field;
    char Set(int v);
};
char Obj_11c1a0::Set(int v) {
    int* q = &field;
    *q = v;
    return 1;
}