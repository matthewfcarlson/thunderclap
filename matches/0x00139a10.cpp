class Obj_139a10 {
  public:
    char Pad[0x18];
    int Value;
    char Set(int v);
};

char Obj_139a10::Set(int v) {
    Value = v;
    return 1;
}
