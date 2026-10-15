// Same code shape as 0x00069920 (propagated; names are from that function)
class CMoveAddTrack {
  public:
    char pad[0xc];
    float a;
    float b;
    float vfunc_7();
};
float zero_69a00 = 0.0f;
float CMoveAddTrack::vfunc_7() {
    float d = b - a;
    if (d < zero_69a00)
        d = zero_69a00;
    return d;
}