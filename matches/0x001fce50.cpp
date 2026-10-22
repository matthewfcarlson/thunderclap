struct Trip {
    int a, b, c;
};
class CTriggerVolumeManager_1fce50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual unsigned char run(Trip t);
    char pad[0xc9];
    unsigned char flag;
};
struct ThisWrap_001fce50 {
    CTriggerVolumeManager_1fce50* Find(int);
    unsigned char Target(int a, int b, int c, int id, unsigned char enabled);
};
unsigned char ThisWrap_001fce50::Target(int a, int b, int c, int id, unsigned char enabled) {
    CTriggerVolumeManager_1fce50* p = this->Find(id);
    if (!p)
        return 0;
    if (enabled && !p->flag)
        return 0;
    return p->run(*(Trip*)&a);
}