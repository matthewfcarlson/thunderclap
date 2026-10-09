class SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    void helper();
};
class SeqEventChannelSends : public SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventChannelSends* v4(int);
};
extern void __cdecl cleanup(void*, void*);
extern char g_bss[];
SeqEventChannelSends* SeqEventChannelSends::v4(int a) {
    helper();
    if (a & 1)
        cleanup(g_bss, this);
    return this;
}