class Obj_48050 {
  public:
    char pad[0x10];
    int mVal;
    char SetMotionState_00048050(int x);
};

char Obj_48050::SetMotionState_00048050(int x) {
    mVal = x;
    return 1;
}
