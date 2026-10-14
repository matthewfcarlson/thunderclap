class Obj_16edd0 {
  public:
    char pad[0x4c];
    int mValue;
    char Set(int v);
};

char Obj_16edd0::Set(int v) {
    mValue = v;
    return 1;
}
