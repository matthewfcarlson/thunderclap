class CExtraRenderingCallback {
  public:
    virtual void f0();
    int a[6];
    CExtraRenderingCallback();
};
CExtraRenderingCallback::CExtraRenderingCallback() {
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
}