extern void* g_vftable_1831b0[];
extern "C" void _ReadWriteBarrier();
void operator delete(void*);
class Str_1831b0 {
  public:
    void Init();
};
class Track_1831b0 {
  public:
    void* vptr;
    char pad[20];
    Str_1831b0 s;
    void Fin();
};
class PropSetStateByNameTrack_1831b0 : public Track_1831b0 {
  public:
    void* Del(unsigned char flags);
};
void* PropSetStateByNameTrack_1831b0::Del(unsigned char flags) {
    vptr = g_vftable_1831b0;
    s.Init();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
