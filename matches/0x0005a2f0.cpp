class Obj_5a2f0 {
  public:
    char pad[0x14];
    int mValue;
    char Set(int v);
};
char Obj_5a2f0::Set(int v) {
    mValue = v;
    return 1;
}