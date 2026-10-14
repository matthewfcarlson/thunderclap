extern void* g_vftable[];
class Base {
  public:
    Base();
    virtual ~Base();
    char pad0[8];
};
class MotionStopTrack : public Base {
  public:
    MotionStopTrack();
    virtual ~MotionStopTrack();
    int m0c;
    float m10;
};
MotionStopTrack::MotionStopTrack() : Base() {
    *(void**)((char*)this + 0) = g_vftable;
    m0c = 0;
    m10 = -1.0f;
}
