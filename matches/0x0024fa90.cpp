extern "C" void* __cdecl Alloc(void*);
extern "C" int __cdecl Lookup(const char*, int);
extern int bss;
namespace audio {
class SeqEventType {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void* vfunc_3();
    SeqEventType();
};
class SeqEventChannelSends : public SeqEventType {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void* vfunc_3();
    char pad[4];
    int data[64];
    int member;
    SeqEventChannelSends() : SeqEventType() {
        member = Lookup("this", 0);
        for (int i = 0; i < 64; ++i)
            data[i] = 0;
    }
};
class SeqEventChannelSendsType {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void* vfunc_3();
};
void* SeqEventChannelSendsType::vfunc_3() {
    SeqEventChannelSends* p = (SeqEventChannelSends*)Alloc(&bss);
    if (p) {
        p->SeqEventChannelSends::SeqEventChannelSends();
        return p;
    }
    return 0;
}
} // namespace audio