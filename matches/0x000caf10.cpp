class SubObj {
  public:
    void Helper(int arg);
};

class Obj {
  public:
    char mPad[0x88];
    SubObj* mThing;
    void Target(int arg);
};

void Obj::Target(int arg) {
    if (mThing)
        mThing->Helper(arg);
}
