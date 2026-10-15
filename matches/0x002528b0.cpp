typedef unsigned __int64 U64;
extern U64 __cdecl MakeValue(const char*, int, int) throw();
class Temp {
    char data[12];

  public:
    Temp(const char*, int, const U64&, int, int) throw();
    ~Temp() throw();
};
class Base {
  public:
    Base(const Temp&) throw();
    virtual void v();
};
class audioSeqEventVarVolumeType : public Base {
  public:
    audioSeqEventVarVolumeType() throw();
    virtual void v();
};
audioSeqEventVarVolumeType::audioSeqEventVarVolumeType() throw()
    : Base(Temp("Vol", 0, MakeValue("SeqEventVarVolume", 0, 0), 12, 4)) {}