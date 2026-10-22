extern "C" __int64 __cdecl GetId(const char*, int, int) throw();
class Temp {
  public:
    Temp* Init(const char*, int) throw();
    ~Temp() throw();
    char pad[12];
};
class SeqEventType_24f950 {
  public:
    SeqEventType_24f950(Temp*, const __int64&, int, int) throw();
    virtual void v0();
};
class SeqEventChannelSendsType_24f950 : public SeqEventType_24f950 {
  public:
    SeqEventChannelSendsType_24f950();
    virtual void v0();
};
SeqEventChannelSendsType_24f950::SeqEventChannelSendsType_24f950()
    : SeqEventType_24f950(Temp().Init("ChSends", 0), GetId("SeqEventChannelSends", 0, 0), 0x10c, 4) {}