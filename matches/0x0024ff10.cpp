typedef unsigned int size_t;
extern char bss;
extern void* __cdecl alloc(void*);
inline void* operator new(size_t, void* heap) {
    return alloc(heap);
}
namespace audio {
class SeqEventCondition;
class SeqCommandCondition {
  public:
    virtual void f0() {}
    virtual void f1() {}
    char pad[4];
    SeqEventCondition* owner;
    int value;
    SeqCommandCondition(SeqEventCondition* p) : owner(p), value(-1) {}
};
class Receiver {
  public:
    void send(SeqCommandCondition*);
};
class SeqEventCondition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(Receiver*);
};
void SeqEventCondition::vfunc_2(Receiver* r) {
    r->send(new (&bss) SeqCommandCondition(this));
}
} // namespace audio