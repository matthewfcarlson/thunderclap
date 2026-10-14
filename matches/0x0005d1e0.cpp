class CHapticTrack {
  public:
    char pad[0x1c];
    unsigned char value;
    float vfunc_7();
};
extern const float gZero_5d1e0;
extern const float gMinusOne_5d1e0;
float CHapticTrack::vfunc_7() {
    if (value)
        return gMinusOne_5d1e0;
    return gZero_5d1e0;
}