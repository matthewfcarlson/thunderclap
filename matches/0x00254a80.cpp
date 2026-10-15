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
extern "C" char __cdecl check(void*, int*);
int audio::SeqEventLogicRepeat::vfunc_0(void* p) {
    if ((char)SeqEvent::vfunc_0(p)) {
        if ((char)SeqEventContainer::vfunc_0(p)) {
            if (check(p, &a)) {
                if (check(p, &b)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}