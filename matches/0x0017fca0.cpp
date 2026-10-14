class Obj {
  public:
    char Pad[0x1c];
    int Value;
    char Set(int v);
};

char Obj::Set(int v) {
    Value = v;
    return 1;
}
