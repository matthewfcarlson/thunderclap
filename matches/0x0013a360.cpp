// Same code shape as 0x0012b640 (propagated; names are from that function)
extern int vtable;
class Helper {
  public:
    void Init();
};
class Ender {
  public:
    void Finish();
};
class ThreatBallTrack {
  public:
    virtual void v0();
    char pad[0x30 - 4];
    void Run();
};
void ThreatBallTrack::Run() {
    *(int*)this = (int)&vtable;
    ((Helper*)((char*)this + 0x30))->Init();
    ((Helper*)((char*)this + 0x18))->Init();
    ((Ender*)this)->Finish();
}
