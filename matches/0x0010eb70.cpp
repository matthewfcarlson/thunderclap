extern void* g_vftable_10eb70[];
void operator delete(void*);
class Sub_10eb70 {
  public:
    void Fini();
};
class Track_10eb70 {
  public:
    void* vptr;
    void Fin();
};
class AIHistorySetTrack_10eb70 : public Track_10eb70 {
  public:
    char pad[0x14];
    Sub_10eb70 m18;
    AIHistorySetTrack_10eb70* f2(unsigned char flags);
};
AIHistorySetTrack_10eb70* AIHistorySetTrack_10eb70::f2(unsigned char flags) {
    vptr = g_vftable_10eb70;
    m18.Fini();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
