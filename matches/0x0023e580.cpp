class Inner {
  public:
    void Init();
};
class StopTrack {
  public:
    char pad[0x14];
    virtual void V();
    void Finish();
    void Ctor();
};
extern int StopTrack_vftable;
void StopTrack::Ctor() {
    *(int*)this = (int)&StopTrack_vftable;
    ((Inner*)((char*)this + 0x14))->Init();
    Finish();
}