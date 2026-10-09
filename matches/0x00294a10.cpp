extern int viewvt, refvt;
class IRefCount {
  public:
    virtual void A();
    virtual void Release();
};
class View {
  public:
    char* v;
    char pad[0x14];
    IRefCount* mRef;
    char pad2[0x20];
    IRefCount* arr[32];
    void Cleanup();
};
void View::Cleanup() {
    ((int*)this)[0] = (int)&viewvt;
    if (mRef)
        mRef->Release();
    for (int i = 0; i < 32; i++) {
        if (arr[i]) {
            arr[i]->Release();
            arr[i] = 0;
        }
    }
    ((int*)this)[0] = (int)&refvt;
}
