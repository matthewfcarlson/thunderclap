class Obj_48120 {
  public:
    char pad[0x10];
    int mVal;
    char Set(int x);
};
char Obj_48120::Set(int x) {
    mVal = x;
    return 1;
}
