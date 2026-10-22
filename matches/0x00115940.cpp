extern void* g_vftable[];
class Track_115940 {
  public:
    Track_115940();
    virtual ~Track_115940();
    char pad0[8];
};
class MotionStopTrack : public Track_115940 {
  public:
    MotionStopTrack();
    virtual ~MotionStopTrack();
    int m0c;
    float m10;
};
MotionStopTrack::MotionStopTrack() : Track_115940() {
    *(void**)((char*)this + 0) = g_vftable;
    m0c = 0;
    m10 = -1.0f;
}
