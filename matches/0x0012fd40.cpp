extern void* g_vftable_12fd40[];
void operator delete(void*);
void operator delete[](void*);
class Track_12fd40 {
  public:
    void* vptr;
    void Fin();
};
class StatBeginTrialTrack_12fd40 : public Track_12fd40 {
  public:
    char pad[0x10 - 4];
    void* m10;
    StatBeginTrialTrack_12fd40* f5(unsigned char flags);
};
StatBeginTrialTrack_12fd40* StatBeginTrialTrack_12fd40::f5(unsigned char flags) {
    void* p = m10;
    vptr = g_vftable_12fd40;
    operator delete[](p);
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
