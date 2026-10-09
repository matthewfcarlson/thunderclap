extern void* __cdecl Alloc(unsigned int);
extern char statVftable[];
class TrackFactory {
  public:
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
};
class StatEndTrialTrack {
  public:
    int pad[3];
    int a;
    int b;
    StatEndTrialTrack();
};
class Factory : public TrackFactory {
  public:
    StatEndTrialTrack* vfunc5();
};
StatEndTrialTrack* Factory::vfunc5() {
    StatEndTrialTrack* p = (StatEndTrialTrack*)Alloc(0x14);
    if (p) {
        p->StatEndTrialTrack::StatEndTrialTrack();
        *(int*)p = (int)statVftable;
        p->a = 0;
        p->b = 0;
        return p;
    }
    return 0;
}
