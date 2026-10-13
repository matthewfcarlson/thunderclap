class Obj {
  public:
    char pad[0x54];
    int field;
    char Set(int v);
};
char Obj::Set(int v) {
    int* q = &field;
    *q = v;
    return 1;
}