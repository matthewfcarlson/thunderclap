class Temp {
  public:
    Temp(const char*, int, const __int64&, int, int) throw();
    ~Temp() throw();
    char pad[12];
};
class Base {
  public:
    virtual void f();
    Base(const Temp&) throw();
};
class audio_SeqEventVarTempoType : public Base {
  public:
    virtual void f();
    audio_SeqEventVarTempoType();
};
extern __int64 __cdecl Make(const char*, int, int);
audio_SeqEventVarTempoType::audio_SeqEventVarTempoType()
    : Base(Temp("4/4", 0, Make("SeqEventVarTempo", 0, 0), 20, 4)) {}