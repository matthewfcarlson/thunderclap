typedef unsigned __int64 U64;
extern U64 __cdecl MakeValue(const char*, int, int) throw();
class Temp {
    char data[12];

  public:
    Temp* Init(const char*, int) throw();
    ~Temp() throw();
};
class SeqEventType_2528b0 {
  public:
    SeqEventType_2528b0(Temp*, const U64&, int, int) throw();
    virtual void v();
};
class SeqEventVarVolumeType_2528b0 : public SeqEventType_2528b0 {
  public:
    SeqEventVarVolumeType_2528b0() throw();
    virtual void v();
};
SeqEventVarVolumeType_2528b0::SeqEventVarVolumeType_2528b0() throw()
    : SeqEventType_2528b0(Temp().Init("Vol", 0), MakeValue("SeqEventVarVolume", 0, 0), 12, 4) {}