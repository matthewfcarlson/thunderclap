extern "C" __int64 __cdecl GetId(const char*, int, int) throw();
class Temp {
  public:
    Temp(const char*, int, const __int64&, int, int) throw();
    ~Temp() throw();
    char pad[12];
};
class Base {
  public:
    Base(const Temp&) throw();
    virtual void v0();
};
class audio_SeqEventChannelSendsType : public Base {
  public:
    audio_SeqEventChannelSendsType();
    virtual void v0();
};
audio_SeqEventChannelSendsType::audio_SeqEventChannelSendsType()
    : Base(Temp("ChSends", 0, GetId("SeqEventChannelSends", 0, 0), 0x10c, 4)) {}