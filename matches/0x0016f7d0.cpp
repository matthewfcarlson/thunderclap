class Obj_16f7d0 {
  public:
    char Pad[0x40];
    int mValue;
    char Set(int v);
};

char Obj_16f7d0::Set(int v) {
    mValue = v;
    return 1;
}
