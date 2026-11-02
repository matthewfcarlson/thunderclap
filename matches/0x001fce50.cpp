// a..c: a 3-word value passed by value and forwarded to the volume's slot 8. A by-value struct parameter can't be
// declared in include/gen (tools/gen_headers.py nv_sig_type), so the member is defined on a local stand-in.
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
struct CTriggerVolumeManager_nv_1fce50 {
    CTriggerVolumeManager_1fce50* Find(int);
    unsigned char FUN_001fce50(Trip a, int id, unsigned char enabled);
};

unsigned char CTriggerVolumeManager_nv_1fce50::FUN_001fce50(Trip a, int id, unsigned char enabled) {
    CTriggerVolumeManager_1fce50* p = Find(id);
    if (!p)
        return 0;
    if (enabled && !p->flag)
        return 0;
    return p->run(a);
}
