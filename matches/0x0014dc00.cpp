class Track_14dc00 {
  public:
    Track_14dc00();
    virtual void a();
    char pad[8];
    int a0;
    char pad2[8];
    int a1;
    char pad3[8];
    int a2;
    int a3;
};
class HitThrowTrack : public Track_14dc00 {
  public:
    HitThrowTrack();
    virtual void a();
};
HitThrowTrack::HitThrowTrack() : Track_14dc00() {
    a0 = 0;
    a1 = 0;
    a2 = 0;
    a3 = 0;
    *(float*)((char*)this + 0x10) = -1.0f;
    *((char*)this + 0x14) = 1;
    *(float*)((char*)this + 0x1c) = 30.0f;
    *(int*)((char*)this + 0x20) = -5;
}