class Arg_215d0 {
  public:
    virtual void F0();
    virtual void F1();
};
class CAction {
  public:
    CAction();
    virtual void F0();
    char pad[24];
    Arg_215d0* mArg;
};
class CClearHitRecordsAction : public CAction {
  public:
    CClearHitRecordsAction(Arg_215d0*);
    virtual void F0();
};
extern int vt1_215d0, vt2;
CClearHitRecordsAction::CClearHitRecordsAction(Arg_215d0* p) {
    *(int*)this = (int)&vt1_215d0;
    int* q = (int*)&mArg;
    *q = 0;
    if (p)
        p->F0();
    if (mArg)
        mArg->F1();
    mArg = p;
    *(int*)this = (int)&vt2;
}
