extern void* g_vA[];
void operator delete(void*);
struct Sub_172e00 {
    void* v;
    void Fin();
};
class Track_172e00 {
  public:
    void* vptr;
    void Fin();
};
class RestPoseTrack_172e00 : public Track_172e00 {
  public:
    char pad[0x18 - 4];
    Sub_172e00 sub;
    RestPoseTrack_172e00* f5(unsigned char flags);
};
RestPoseTrack_172e00* RestPoseTrack_172e00::f5(unsigned char flags) {
    vptr = g_vA;
    sub.Fin();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
