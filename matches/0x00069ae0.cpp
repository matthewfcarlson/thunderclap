// Same code shape as 0x00069920 (propagated; names are from that function)
class CMoveAddYTrack {
  public:
    char pad[0xc];
    float a;
    float b;
    float vfunc_7();
};
float zero_69ae0 = 0.0f;
float CMoveAddYTrack::vfunc_7() {
    float d = b - a;
    if (d < zero_69ae0)
        d = zero_69ae0;
    return d;
}