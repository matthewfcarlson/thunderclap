extern void* g_vftable_10ebd0[];
extern "C" void _ReadWriteBarrier();
void operator delete(void*);
class Str_10ebd0 {
  public:
    void Init();
};
class Track_10ebd0 {
  public:
    void* vptr;
    char pad[20];
    Str_10ebd0 s;
    void Fin();
};
class SemaphoreWaitTrack_10ebd0 : public Track_10ebd0 {
  public:
    void* Del(unsigned char flags);
};
void* SemaphoreWaitTrack_10ebd0::Del(unsigned char flags) {
    vptr = g_vftable_10ebd0;
    s.Init();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
