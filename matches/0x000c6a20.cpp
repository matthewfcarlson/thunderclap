class Arg {
  public:
    virtual void F();
    int G();
};
class Obj {
  public:
    Arg* mArg;
    volatile int mOne;
    char pad[0x3fc];
    volatile int mIndex;
    int m408;
    int m40c;
    Obj* Run(Arg*);
};
Obj* Obj::Run(Arg* arg) {
    mArg = arg;
    if (arg) {
        arg->F();
        if (mArg) {
            mIndex = 0;
            mOne = 0;
            ((int*)this)[mIndex * 2 + 2] = 0;
            m408 = mArg->G();
            m40c = 0;
        }
    }
    return this;
}
