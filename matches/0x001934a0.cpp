class Obj_1934a0 {
  public:
    char Pad[0xb4];
    int Value;
    char Set(int x);
};
char Obj_1934a0::Set(int x) {
    Value = x;
    return 1;
}
