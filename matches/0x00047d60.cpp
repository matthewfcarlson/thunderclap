class Obj_47d60 {
  public:
    char Set(int v);
    char pad[0x10];
    int mValue;
};
char Obj_47d60::Set(int v) {
    mValue = v;
    return 1;
}
