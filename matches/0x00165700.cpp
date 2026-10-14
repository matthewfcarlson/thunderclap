class Obj_165700 {
  public:
    char pad[0x10];
    int mField;
    char Set(int v);
};
char Obj_165700::Set(int v) {
    mField = v;
    return 1;
}
