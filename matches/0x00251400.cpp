class SeqEvent {
  public:
    virtual int dummy();
    bool vfunc_0(void*);
};
extern bool __cdecl ParseA(void*, void*);
extern bool __cdecl ParseB(void*, void*);
extern bool __cdecl ParseC(void*, void*);
extern bool __cdecl ParseD(void*, void*);
class SeqEventPlayTrack : public SeqEvent {
  public:
    char pad[4];
    int a, b, c, d;
    virtual int vfunc_0(void*);
};
int SeqEventPlayTrack::vfunc_0(void* p) {
    if (SeqEvent::vfunc_0(p) && ParseA(p, &a) && ParseB(p, &b) && ParseC(p, &c) && ParseD(p, &d))
        return 1;
    return 0;
}