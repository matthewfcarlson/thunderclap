class Obj_10c5f0 {
  public:
    char Pad[0x20];
    int value;
    char Set(int v);
};

char Obj_10c5f0::Set(int v) {
    value = v;
    return 1;
}
