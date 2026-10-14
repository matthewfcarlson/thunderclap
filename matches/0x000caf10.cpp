class SubObj_caf10 {
  public:
    void Helper(int arg);
};

class Obj_caf10 {
  public:
    char mPad[0x88];
    SubObj_caf10* mThing;
    void Target(int arg);
};

void Obj_caf10::Target(int arg) {
    if (mThing)
        mThing->Helper(arg);
}
