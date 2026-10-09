// Same code shape as 0x0005d1d0 (propagated; names are from that function)
class CHapticTrack {
  public:
    char pad[0x10];
    float value;
    float vfunc_14();
};
float CHapticTrack::vfunc_14() {
    return value;
}