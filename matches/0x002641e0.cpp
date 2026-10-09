class Obj {
  public:
    virtual void X();
    virtual void Release();
};
class LoadStream {
  public:
    unsigned int vt;
    unsigned int p4;
    Obj* mObj;
    unsigned int pC[5];
    void* m20;
    void* m24;
    void Init();
    void Destroy();
};
void Cleanup(void*);
void LoadStream::Destroy() {
    vt = 0x42ae9c;
    Init();
    if (mObj)
        mObj->Release();
    if (m20)
        Cleanup(m20);
    if (m24)
        Cleanup(m24);
    vt = 0x3f6098;
}
