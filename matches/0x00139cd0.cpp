class Obj_139cd0 {
  public:
    char pad[0x24];
    int Value;
    char Set(int x);
};

char Obj_139cd0::Set(int x) {
    Value = x;
    return 1;
}
