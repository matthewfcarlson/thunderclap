class Obj_47ac0 {
  public:
    char pad[0x10];
    int mVal;
    char Set(int v);
};
char Obj_47ac0::Set(int v) {
    mVal = v;
    return 1;
}
