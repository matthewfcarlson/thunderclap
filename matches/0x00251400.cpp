class SeqEvent {
  public:
    virtual int dummy();
    bool vfunc_0(void*);
};
extern "C" bool __cdecl FUN_0025abd0(void*, void*);
extern "C" bool __cdecl FUN_0025abd0(void*, void*);
extern "C" bool __cdecl FUN_0025aa80(void*, void*);
extern "C" bool __cdecl FUN_0025bce0(void*, void*);
class SeqEventPlayTrack : public SeqEvent {
  public:
    char pad[4];
    int a, b, c, d;
    virtual int vfunc_0(void*);
};
int SeqEventPlayTrack::vfunc_0(void* p) {
    if (SeqEvent::vfunc_0(p) && FUN_0025abd0(p, &a) && FUN_0025abd0(p, &b) && FUN_0025aa80(p, &c) && FUN_0025bce0(p, &d))
        return 1;
    return 0;
}