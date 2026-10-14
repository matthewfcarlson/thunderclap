class Obj_146ef0 {
  public:
    char pad[0x2c];
    int value;
    char Set(int v);
};

char Obj_146ef0::Set(int v) {
    value = v;
    return 1;
}
