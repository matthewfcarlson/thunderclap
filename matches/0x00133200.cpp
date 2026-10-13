class Obj {
  public:
    char Pad[0x10];
    int Value;
    char Set(int v);
};
char Obj::Set(int v) {
    Value = v;
    return 1;
}
