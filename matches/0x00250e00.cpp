class SeqEvent {
  public:
    virtual char vfunc_0(void*);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5();
};
extern char __cdecl ParseA(void*, void*);
extern char __cdecl ParseB(void*, void*);
extern char __cdecl ParseC(void*, void*);
class SeqEventStopTrack : public SeqEvent {
  public:
    char m8[4];
    char mC[4];
    char m10[12];
    virtual int vfunc_0(int*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
int SeqEventStopTrack::vfunc_0(int* p) {
    if (SeqEvent::vfunc_0(p)) {
        if (ParseA(p, (char*)this + 8)) {
            if (ParseA(p, (char*)this + 12)) {
                if (ParseB(p, (char*)this + 16)) {
                    if (ParseC(p, (char*)this + 28))
                        return 1;
                }
            }
        }
    }
    return 0;
}