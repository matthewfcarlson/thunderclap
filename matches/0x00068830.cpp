class Obj_68830 {
  public:
    char Pad[0x30];
    int Value;
    char Set(int v);
};

char Obj_68830::Set(int v) {
    Value = v;
    return 1;
}
