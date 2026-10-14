class Obj {
  public:
    char Pad[0x54];
    int Value;
    char Set(int x);
};
char Obj::Set(int x) {
    Value = x;
    return 1;
}