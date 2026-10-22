extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1732c0[];
void operator delete(void*);
class Mem_1732c0 {
  public:
    ~Mem_1732c0();
};
class Track_1732c0 {
  public:
    void* vptr;
    void Fin();
};
class FootPivotTrack_1732c0 : public Track_1732c0 {
  public:
    char pad[20];
    Mem_1732c0 m;
    FootPivotTrack_1732c0* f2(unsigned char flags);
};
FootPivotTrack_1732c0* FootPivotTrack_1732c0::f2(unsigned char flags) {
    vptr = g_vftable_1732c0;

    m.~Mem_1732c0();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
