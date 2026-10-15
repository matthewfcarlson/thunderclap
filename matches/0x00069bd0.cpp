// Same code shape as 0x00069920 (propagated; names are from that function)
class CSweepTrack {
  public:
    char pad[0xc];
    float a;
    float b;
    float vfunc_7();
};
float zero_69bd0 = 0.0f;
float CSweepTrack::vfunc_7() {
    float d = b - a;
    if (d < zero_69bd0)
        d = zero_69bd0;
    return d;
}