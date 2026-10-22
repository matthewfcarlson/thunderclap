class Track_170ce0 {
  public:
    Track_170ce0();
    virtual void f();
};
class IntentionClearTrack : public Track_170ce0 {
  public:
    IntentionClearTrack();
    char pad[4];
    volatile int a;
    int b;
    float c;
};
IntentionClearTrack::IntentionClearTrack() : Track_170ce0() {
    b = 0;
    c = -1.0f;
    a = 1;
}