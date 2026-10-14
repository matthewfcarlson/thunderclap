class Obj_17fca0 {
  public:
    char Pad[0x1c];
    int Value;
    char Set(int v);
};

char Obj_17fca0::Set(int v) {
    Value = v;
    return 1;
}
