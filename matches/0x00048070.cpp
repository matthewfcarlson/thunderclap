class Obj_48070 {
  public:
    char pad[0x10];
    int mValue;
    bool SetMotionHit_00048070(int arg);
};

bool Obj_48070::SetMotionHit_00048070(int arg) {
    mValue = arg;
    return true;
}
