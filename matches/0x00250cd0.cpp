typedef unsigned int size_t;
extern char bss;
extern "C" void* __cdecl allocate(void*);
namespace audio {
class SeqEventExpression;
class SeqActionExpression {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    char pad[4];
    SeqEventExpression* owner;
    int val;
    SeqActionExpression(SeqEventExpression* p) : owner(p), val(0) {}
    static void* operator new(size_t) { return allocate(&bss); }
};
class Engine {
  public:
    void send(SeqActionExpression*);
};
class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
class SeqEventExpression : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(Engine*);
};
} // namespace audio
void audio::SeqEventExpression::vfunc_2(audio::Engine* e) {
    e->send(new audio::SeqActionExpression(this));
}