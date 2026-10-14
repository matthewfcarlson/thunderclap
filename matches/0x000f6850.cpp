// Same code shape as 0x000c6a20 (propagated; names are from that function)
class Arg_f6850 {
  public:
    virtual void F();
    int G();
};
class Obj_f6850 {
  public:
    Arg_f6850* mArg;
    volatile int mOne;
    char pad[0x3fc];
    volatile int mIndex;
    int m408;
    int m40c;
    Obj_f6850* Run(Arg_f6850*);
};
Obj_f6850* Obj_f6850::Run(Arg_f6850* arg) {
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
