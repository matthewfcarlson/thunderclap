class Obj_47b40 {
  public:
    char SetSpeed_00047b40(int v);
    char pad[0x14];
    int mField;
};

char Obj_47b40::SetSpeed_00047b40(int v) {
    mField = v;
    return 1;
}
