class Obj_68640 {
  public:
    char Pad[0x10];
    int Value;
    char Set(int v);
};

char Obj_68640::Set(int v) {
    Value = v;
    return 1;
}
