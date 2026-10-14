extern "C" __int64 __cdecl GetId(const char*, int, int) throw();
class Temp {
  public:
    Temp(const char*, int, const __int64&, int, int) throw();
    ~Temp() throw();
    char pad[12];
};
class Base_24f950 {
  public:
    Base_24f950(const Temp&) throw();
    virtual void v0();
};
class audio_SeqEventChannelSendsType : public Base_24f950 {
  public:
    audio_SeqEventChannelSendsType();
    virtual void v0();
};
audio_SeqEventChannelSendsType::audio_SeqEventChannelSendsType()
    : Base_24f950(Temp("ChSends", 0, GetId("SeqEventChannelSends", 0, 0), 0x10c, 4)) {}