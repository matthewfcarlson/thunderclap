extern "C" char DAT_003fd094[];
class StopTrack {
  public:
    void Init();
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual StopTrack* Make();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
StopTrack* Factory::Make() {
    StopTrack* p = (StopTrack*)FUN_0008d690(0x18);
    if (p) {
        p->Init();
        *(int*)p = ((int)DAT_003fd094);
        return p;
    }
    return 0;
}