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
    Data* Init(const char*, int) throw();
    ~Data() throw();
};
class SeqEventType_24ed10 {
  public:
    SeqEventType_24ed10(Data*, void*, int, int) throw();
    virtual void f();
};
class SeqEventChannelSendVolumesType_24ed10 : public SeqEventType_24ed10 {
  public:
    SeqEventChannelSendVolumesType_24ed10() throw();
    virtual void f();
};
SeqEventChannelSendVolumesType_24ed10::SeqEventChannelSendVolumesType_24ed10() throw()
    : SeqEventType_24ed10(Data().Init("ChSendVol", 0), Key(Lookup("SeqEventChannelSendVolumes", 0, 0)), 0x50, 4) {}