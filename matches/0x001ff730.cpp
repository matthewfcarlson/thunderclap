class CTriggerVolumeManager {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char* vfunc_3(int x);
    int mDummy;
};

char* CTriggerVolumeManager::vfunc_3(int x) {
    return (char*)(x ? "Volume" : "Locator");
}
