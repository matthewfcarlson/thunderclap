extern __int64 __cdecl make(const char*, int, int) throw();
extern char data;
class Arg {
    char pad[12];

  public:
    Arg* Init(const char*, int) throw();
    ~Arg() throw();
};
class SeqEventType_254f40 {
  public:
    SeqEventType_254f40(Arg*, const __int64&, int, int) throw();
    virtual void f();
};
class SeqEventLogicOrType_254f40 : public SeqEventType_254f40 {
  public:
    SeqEventLogicOrType_254f40() throw();
    virtual void g();
};
SeqEventLogicOrType_254f40::SeqEventLogicOrType_254f40() throw()
    : SeqEventType_254f40(Arg().Init(&data, 0), make("SeqEventLogicOr", 0, 0), 0x18, 4) {}