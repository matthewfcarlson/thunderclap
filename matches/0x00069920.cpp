class CMoveTrack {
  public:
    char pad[0xc];
    float a;
    float b;
    float vfunc_7();
};
float zero_69920 = 0.0f;
float CMoveTrack::vfunc_7() {
    float d = b - a;
    if (d < zero_69920)
        d = zero_69920;
    return d;
}