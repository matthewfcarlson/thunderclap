extern "C" void _ReadWriteBarrier();
namespace audio {
class SeqEvent {
  public:
    SeqEvent();
    virtual void f();
    char pad[4];
};
class SeqEventVarTempo : public SeqEvent {
  public:
    SeqEventVarTempo();
    virtual void f();
    int a;
    int b;
    float tempo;
};
SeqEventVarTempo::SeqEventVarTempo() : SeqEvent(), a(4), b(4), tempo(120.0f) {
    _ReadWriteBarrier();
}
} // namespace audio