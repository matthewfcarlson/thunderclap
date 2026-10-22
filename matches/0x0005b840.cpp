extern void* g_vftable_5b840[];
void operator delete(void*);
struct T1 {
    void Fini();
};
struct T2 {
    void Fini();
};
class Track_5b840 {
  public:
    void* vptr;
    void Fin();
};
class CGrappleOpportunityTrack : public Track_5b840 {
  public:
    char pad4[0x14];
    T2 a18;
    char pad19[0x28 - 0x19];
    T1 a28;
    CGrappleOpportunityTrack* vfunc_5(unsigned char flags);
};
CGrappleOpportunityTrack* CGrappleOpportunityTrack::vfunc_5(unsigned char flags) {
    vptr = g_vftable_5b840;
    a28.Fini();
    a18.Fini();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
