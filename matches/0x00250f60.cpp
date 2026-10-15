extern "C" __int64 __cdecl make(const char*, int, int);
struct Arg {
    __int64 val;
    Arg() throw() : val(make("SeqEventStopTrack", 0, 0)) {}
};
class Name {
  public:
    char pad[12];
    Name(const char*, int, const Arg&, int, int) throw();
    ~Name() throw();
};
class Base {
  public:
    Base(const Name&) throw();
    virtual void f();
};
class audioSeq : public Base {
  public:
    audioSeq();
    virtual void f();
};
audioSeq::audioSeq() : Base(Name("Stop", 0, Arg(), 32, 4)) {}