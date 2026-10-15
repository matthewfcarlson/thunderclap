namespace audio {
class SeqEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
class SeqActionStopTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad[4];
    SeqEvent* event;
    int field;
    SeqActionStopTrack(SeqEvent* e) : event(e), field(0) {}
};
class Track {
  public:
    void action(SeqActionStopTrack*);
};
class SeqEventStopTrack : public SeqEvent {
  public:
    virtual void vfunc_2(void*);
};
} // namespace audio
extern char bss;
extern "C" void* __cdecl FUN_00247530(void*);
inline void* operator new(unsigned int, char* p) {
    return FUN_00247530(p);
}
void audio::SeqEventStopTrack::vfunc_2(void* p) {
    ((Track*)p)->action(new (&bss) SeqActionStopTrack(this));
}