class Action {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};

class StatEndTrialAction : public Action {
  public:
    void vfunc_4();
};

void StatEndTrialAction::vfunc_4() {
    return;
}
