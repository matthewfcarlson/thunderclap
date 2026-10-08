class CHapticTrack { public: char pad[0x1c]; unsigned char value; float vfunc_7(); };
extern const float gZero;
extern const float gMinusOne;
float CHapticTrack::vfunc_7() { if (value) return gMinusOne; return gZero; }