class Obj_165620 {
  public:
    char Pad[0x24];
    int Value;
    char Set(int x);
};
char Obj_165620::Set(int x) {
    Value = x;
    return 1;
}
