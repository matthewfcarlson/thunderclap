class Obj_133860 {
  public:
    char Pad[0x20];
    int Value;
    char Set(int v);
};

char Obj_133860::Set(int v) {
    Value = v;
    return 1;
}
