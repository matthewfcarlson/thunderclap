extern "C" char DAT_004d4143[];
class CameraAnimationController {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual bool vfunc_26(void* p);
};
bool CameraAnimationController::vfunc_26(void* p) {
    if (p != 0) {
        if (*(int*)((char*)p + 0x28) > 0) {
            return *(int*)((char*)p + 0x1c) == ((int)DAT_004d4143);
        }
    }
    return false;
}
