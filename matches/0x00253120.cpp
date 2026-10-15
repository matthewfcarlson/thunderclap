extern __int64 __cdecl makeValue(const char*, int, int) throw();
class Param {
  public:
    Param(const char*, int, const __int64&, int, int) throw();
    ~Param() throw();
    char pad[12];
};
class Base {
  public:
    Base(const Param&) throw();
    virtual void a();
};
class audioSeqEventVarPosDistType : public Base {
  public:
    audioSeqEventVarPosDistType() throw();
    virtual void a();
};
audioSeqEventVarPosDistType::audioSeqEventVarPosDistType() throw()
    : Base(Param("3d", 0, makeValue("SeqEventVarPosDist", 0, 0), 16, 4)) {}
