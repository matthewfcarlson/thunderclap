extern __int64 __cdecl makeValue(const char*, int, int) throw();
class Param {
  public:
    Param* Init(const char*, int) throw();
    ~Param() throw();
    char pad[12];
};
class Base {
  public:
    Base(Param*, const __int64&, int, int) throw();
    virtual void a();
};
class audioSeqEventVarPosDistType : public Base {
  public:
    audioSeqEventVarPosDistType() throw();
    virtual void a();
};
audioSeqEventVarPosDistType::audioSeqEventVarPosDistType() throw()
    : Base(Param().Init("3d", 0), makeValue("SeqEventVarPosDist", 0, 0), 16, 4) {}
