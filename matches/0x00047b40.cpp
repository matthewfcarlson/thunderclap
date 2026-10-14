class Obj_47b40 {
  public:
    char Set(int v);
    char pad[0x14];
    int mField;
};

char Obj_47b40::Set(int v) {
    mField = v;
    return 1;
}
