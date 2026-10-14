class Arg_c6a20 {
  public:
    virtual void F();
    int G();
};
class Obj_c6a20 {
  public:
    Arg_c6a20* mArg;
    volatile int mOne;
    char pad[0x3fc];
    volatile int mIndex;
    int m408;
    int m40c;
    Obj_c6a20* Run(Arg_c6a20*);
};
Obj_c6a20* Obj_c6a20::Run(Arg_c6a20* arg) {
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
