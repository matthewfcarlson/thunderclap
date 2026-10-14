class Obj_17f880 {
  public:
    char pad[0x2c];
    int value;
    char Set(int v);
};

char Obj_17f880::Set(int v) {
    value = v;
    return 1;
}
