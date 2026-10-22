extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1482f0[];
void operator delete(void*);
class Mem_1482f0 {
  public:
    ~Mem_1482f0();
};
class Track_1482f0 {
  public:
    void* vptr;
    void Fin();
};
class GrappleHitReactionTrack_1482f0 : public Track_1482f0 {
  public:
    char pad[28];
    Mem_1482f0 m;
    GrappleHitReactionTrack_1482f0* f2(unsigned char flags);
};
GrappleHitReactionTrack_1482f0* GrappleHitReactionTrack_1482f0::f2(unsigned char flags) {
    vptr = g_vftable_1482f0;

    m.~Mem_1482f0();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
