class Manager {
  public:
    char pad[0x54];
    char flag;
    void Do(int, int, int);
};
class sSubtitleCallback {
  public:
    virtual void vfunc_0(int, int);
    virtual void vfunc_1();
};
class sSubtitleManagerCallback : public sSubtitleCallback {
  public:
    Manager* mgr;
    virtual void vfunc_0(int a, int b);
};
void sSubtitleManagerCallback::vfunc_0(int a, int b) {
    Manager* p = mgr;
    if (p) {
        if (!p->flag)
            p->Do(2, a, b);
        else
            p->Do(0, a, b);
    }
}