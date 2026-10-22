class Temp {
  public:
    Temp* Init(const char*, int) throw();
    ~Temp() throw();
    char pad[12];
};
class SeqEventType_252d00 {
  public:
    virtual void f();
    SeqEventType_252d00(Temp*, const __int64&, int, int) throw();
};
class SeqEventVarTempoType_252d00 : public SeqEventType_252d00 {
  public:
    virtual void f();
    SeqEventVarTempoType_252d00();
};
extern __int64 __cdecl Make(const char*, int, int);
SeqEventVarTempoType_252d00::SeqEventVarTempoType_252d00()
    : SeqEventType_252d00(Temp().Init("4/4", 0), Make("SeqEventVarTempo", 0, 0), 20, 4) {}