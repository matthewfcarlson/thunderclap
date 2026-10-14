class Obj_5d760 {
  public:
    char Pad[0x2c];
    int Value;
    char Set(int x);
};

char Obj_5d760::Set(int x) {
    Value = x;
    return 1;
}
