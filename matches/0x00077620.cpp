extern void* __cdecl alloc(unsigned int);
class CStageTrack {
  public:
    void Init();
};
class TrackFactoryTemplate {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual CStageTrack* Create();
};
CStageTrack* TrackFactoryTemplate::Create() {
    CStageTrack* p = (CStageTrack*)alloc(0x14);
    if (p) {
        p->Init();
        *(int*)p = 0x3fc094;
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 8) = 1;
        return p;
    }
    return 0;
}