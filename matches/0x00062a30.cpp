class CSmartPropThrowingTrack { public: char pad[0x0c]; float mA; float mB; float vfunc_7(); };
float CSmartPropThrowingTrack::vfunc_7() { float x = mB - mA; if (x <= 0.0f) return -1.0f; return x; }
