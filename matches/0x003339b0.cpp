extern "C" void __stdcall Func_00367610(void*, void*, unsigned int);

class PlayerBink {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10(float param);
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();

  private:
    char pad0[0x1c - 4];
    void* mPtr1c;
    float mParamStore;
    char pad1[4];
    unsigned int mCount;
    void* mArray2c[1];
};

void PlayerBink::vfunc_10(float param) {
    mParamStore = param;
    if (mPtr1c) {
        unsigned int converted = (unsigned int)(param * param * 65536.0f);
        for (unsigned int i = 0; i < mCount; i++) {
            Func_00367610(mPtr1c, mArray2c[i], converted);
        }
    }
}