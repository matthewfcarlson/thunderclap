typedef unsigned int u32;
extern u32 __cdecl MakeThing(const char*, int);
extern u32 VTable;
class Base {
  public:
    void Ctor();
};
class SeqEventChannelSends {
  public:
    u32* vt;
    u32 pad;
    u32 values[64];
    u32 result;
    SeqEventChannelSends();
};
SeqEventChannelSends::SeqEventChannelSends() {
    ((Base*)this)->Ctor();
    vt = &VTable;
    result = MakeThing("this", 0);
    for (int i = 0; i < 64; ++i)
        values[i] = 0;
}