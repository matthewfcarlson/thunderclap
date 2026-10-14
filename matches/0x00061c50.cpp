class Obj_61c50 {
  public:
    char Pad[0xb4];
    int Value;
    char Set(int v);
};
char Obj_61c50::Set(int v) {
    Value = v;
    return 1;
}
