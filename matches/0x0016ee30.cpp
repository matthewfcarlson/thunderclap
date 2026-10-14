class Obj_16ee30 {
  public:
    char pad[0x18];
    int mValue;
    char Set(int v);
};

char Obj_16ee30::Set(int v) {
    mValue = v;
    return 1;
}
