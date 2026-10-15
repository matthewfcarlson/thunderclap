extern "C" __int64 __cdecl Lookup(const char*, int, int) throw();
class Key {
    __int64 n;

  public:
    Key(__int64 v) : n(v) {}
    operator void*() { return &n; }
};
class Data {
    char pad[12];

  public:
    Data(const char*, int, void*, int, int) throw();
    ~Data() throw();
};
class Base {
  public:
    Base(const Data&) throw();
    virtual void f();
};
class audio_SeqEventChannelSendVolumesType : public Base {
  public:
    audio_SeqEventChannelSendVolumesType() throw();
    virtual void f();
};
audio_SeqEventChannelSendVolumesType::audio_SeqEventChannelSendVolumesType() throw()
    : Base(Data("ChSendVol", 0, Key(Lookup("SeqEventChannelSendVolumes", 0, 0)), 0x50, 4)) {}