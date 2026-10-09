class SlowMotionTrack {
  public:
    char pad[0x0c];
    float valueC;
    char pad2[8];
    float value18;
    float vfunc_7();
};
float SlowMotionTrack::vfunc_7() {
    return value18 - valueC;
}