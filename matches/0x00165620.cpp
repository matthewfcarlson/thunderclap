class Obj {
  public:
    char Pad[0x24];
    int Value;
    char Set(int x);
};
char Obj::Set(int x) {
    Value = x;
    return 1;
}
