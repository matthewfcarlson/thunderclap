class Obj_133200 {
  public:
    char Pad[0x10];
    int Value;
    char Set(int v);
};
char Obj_133200::Set(int v) {
    Value = v;
    return 1;
}
