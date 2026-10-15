extern __int64 __cdecl make(const char*, int, int) throw();
extern char data;
class Arg {
    char pad[12];

  public:
    Arg(const char*, int, const __int64&, int, int) throw();
    ~Arg() throw();
};
class Base {
  public:
    Base(const Arg&) throw();
    virtual void f();
};
class audioSeqEventLogicOrType : public Base {
  public:
    audioSeqEventLogicOrType() throw();
    virtual void g();
};
audioSeqEventLogicOrType::audioSeqEventLogicOrType() throw()
    : Base(Arg(&data, 0, make("SeqEventLogicOr", 0, 0), 0x18, 4)) {}