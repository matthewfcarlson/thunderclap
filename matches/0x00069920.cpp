class CMoveTrack { public: char pad[0xc]; float a; float b; float vfunc_7(); };
float zero = 0.0f;
float CMoveTrack::vfunc_7() { float d = b - a; if (d < zero) d = zero; return d; }