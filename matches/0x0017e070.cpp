struct ChargeTrack {
    int vt;
    int pad4;
    int enabled;
    float padc;
    float value10;
    int pad14;
    char flag18;
    char pad19[3];
    float value1c;
    void Init();
};
extern int chargeVtable;
void* operator new(unsigned int);
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual ChargeTrack* vfunc_5();
};
ChargeTrack* Factory::vfunc_5() {
    ChargeTrack* p = (ChargeTrack*)operator new(0x20);
    if (p) {
        p->Init();
        p->vt = (int)&chargeVtable;
        p->padc = 0.0f;
        p->value10 = -1.0f;
        p->pad14 = 0;
        p->flag18 = 0;
        p->value1c = 1.0f;
        p->enabled = 1;
        return p;
    }
    return 0;
}