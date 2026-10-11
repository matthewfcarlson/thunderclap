class TeleportToLocatorTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~TeleportToLocatorTrack();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    int pad04[3];
    int m10;
    void trackCall();
};
extern void __cdecl thunk_FUN_00267090(int);
TeleportToLocatorTrack::~TeleportToLocatorTrack() {
    thunk_FUN_00267090(m10);
    trackCall();
}
