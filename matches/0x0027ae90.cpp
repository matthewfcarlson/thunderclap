class RDLFile {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Ref_27ae90 {
  public:
    virtual void f0();
    virtual void f1();
};
class RDLReader : public RDLFile {
  public:
    Ref_27ae90* mRef;
    void* mThing;
    virtual void vfunc_1();
};
void thunk_FUN_00267090(void*);
void RDLReader::vfunc_1() {
    if (mRef) {
        mRef->f1();
        mRef = 0;
        if (mThing)
            thunk_FUN_00267090(mThing);
    }
}