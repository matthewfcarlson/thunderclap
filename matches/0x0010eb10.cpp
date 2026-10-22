extern void* g_vftable_10eb10[];
extern "C" void _ReadWriteBarrier();
void operator delete(void*);
class Str_10eb10 {
  public:
    void Init();
};
class Track_10eb10 {
  public:
    void* vptr;
    char pad[20];
    Str_10eb10 s;
    void Fin();
};
class KeywordWaitTrack_10eb10 : public Track_10eb10 {
  public:
    void* Del(unsigned char flags);
};
void* KeywordWaitTrack_10eb10::Del(unsigned char flags) {
    vptr = g_vftable_10eb10;
    s.Init();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
