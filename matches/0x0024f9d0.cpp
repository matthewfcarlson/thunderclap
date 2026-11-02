typedef unsigned int u32_24f9d0;
extern "C" u32_24f9d0 __cdecl FUN_002673a0(const char*, int);
extern u32_24f9d0 VTable_24f9d0;
class SeqEventChannelSends_24f9d0 {
  public:
    void Ctor();
};
class SeqEventChannelSends {
  public:
    u32_24f9d0* vt;
    u32_24f9d0 pad;
    u32_24f9d0 values[64];
    u32_24f9d0 result;
    SeqEventChannelSends();
};
SeqEventChannelSends::SeqEventChannelSends() {
    ((SeqEventChannelSends_24f9d0*)this)->Ctor();
    vt = &VTable_24f9d0;
    result = FUN_002673a0("this", 0);
    for (int i = 0; i < 64; ++i)
        values[i] = 0;
}