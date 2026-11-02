namespace audio {
class SeqEvent {
  public:
    virtual int vfunc_0(void*);
};
class SeqEventContainer : public SeqEvent {
  public:
    virtual int vfunc_0(void*);
};
class SeqEventLogicRepeat : public SeqEventContainer {
  public:
    char pad[0x10];
    int a;
    int b;
    virtual int vfunc_0(void*);
};
} // namespace audio
extern "C" char __cdecl FUN_0025abd0(void*, int*);
int audio::SeqEventLogicRepeat::vfunc_0(void* p) {
    if ((char)SeqEvent::vfunc_0(p)) {
        if ((char)SeqEventContainer::vfunc_0(p)) {
            if (FUN_0025abd0(p, &a)) {
                if (FUN_0025abd0(p, &b)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}