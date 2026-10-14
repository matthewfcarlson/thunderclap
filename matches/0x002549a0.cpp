class SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqActionSilence {
  public:
    int vf;
    int pad4;
    void* owner;
    int a;
    float b;
    int pad14;
    int c;
};
class SeqEventSilence : public SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(int);
    virtual void v3();
    virtual void v4();
    int pad4;
    int m8;
    int mc;
};
extern char g_buffer[];
extern void* __cdecl FUN_00247530(void*);
extern int __cdecl FUN_000113e0(int, int);
extern char VT_2549a0[];
class Helper_2549a0 {
  public:
    void FUN_0025dc20(SeqActionSilence*);
};
void SeqEventSilence::v2(int arg) {
    SeqActionSilence* a = (SeqActionSilence*)FUN_00247530(g_buffer);
    SeqActionSilence* r;
    if (a) {
        a->vf = (int)VT_2549a0;
        a->owner = this;
        int x = mc;
        int y = m8;
        int r2 = FUN_000113e0(y, x);
        a->a = 0;
        a->b = (float)r2;
        a->c = 0;
        r = a;
    } else
        r = 0;
    ((Helper_2549a0*)arg)->FUN_0025dc20(r);
}
