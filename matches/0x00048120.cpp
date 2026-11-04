class Obj_48120 {
  public:
    char pad[0x10];
    int mVal;
    char SetTime_00048120(int x);
};
char Obj_48120::SetTime_00048120(int x) {
    mVal = x;
    return 1;
}
