class core_IRefCount {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
};

class core_ControllerOutputPointXBox : public core_IRefCount {
  public:
    virtual char* vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};

char* core_ControllerOutputPointXBox::vfunc_4() {
    return "Analog";
}
