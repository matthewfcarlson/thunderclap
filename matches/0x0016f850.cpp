class Obj_16f850 {
  public:
    char pad[0x18];
    int mValue;
    char Set(int v);
};

char Obj_16f850::Set(int v) {
    mValue = v;
    return 1;
}
