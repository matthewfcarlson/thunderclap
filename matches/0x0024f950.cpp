extern "C" __int64 __cdecl GetId(const char*, int, int) throw();
class Temp {
  public:
    Temp* Init(const char*, int) throw();
    ~Temp() throw();
    char pad[12];
};
class Base_24f950 {
  public:
    Base_24f950(Temp*, const __int64&, int, int) throw();
    virtual void v0();
};
class audio_SeqEventChannelSendsType : public Base_24f950 {
  public:
    audio_SeqEventChannelSendsType();
    virtual void v0();
};
audio_SeqEventChannelSendsType::audio_SeqEventChannelSendsType()
    : Base_24f950(Temp().Init("ChSends", 0), GetId("SeqEventChannelSends", 0, 0), 0x10c, 4) {}