class Obj_16f0a0 {
  public:
    char Pad[0x10];
    int Value;
    char Set(int v);
};

char Obj_16f0a0::Set(int v) {
    Value = v;
    return 1;
}
