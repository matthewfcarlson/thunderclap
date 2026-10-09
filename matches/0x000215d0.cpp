class Arg {
  public:
    virtual void F0();
    virtual void F1();
};
class CAction {
  public:
    CAction();
    virtual void F0();
    char pad[24];
    Arg* mArg;
};
class CClearHitRecordsAction : public CAction {
  public:
    CClearHitRecordsAction(Arg*);
    virtual void F0();
};
extern int vt1, vt2;
CClearHitRecordsAction::CClearHitRecordsAction(Arg* p) {
    *(int*)this = (int)&vt1;
    int* q = (int*)&mArg;
    *q = 0;
    if (p)
        p->F0();
    if (mArg)
        mArg->F1();
    mArg = p;
    *(int*)this = (int)&vt2;
}
