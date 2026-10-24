class Drive {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int);
};

class IRefCount {
  public:
    virtual void vfunc_2(int);
};

class XboxDrive : public Drive, public IRefCount {
  public:
    void vfunc_2(int);
};


XboxDrive g_xbox;
