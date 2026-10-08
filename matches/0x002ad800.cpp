class ImageHandler { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); };
class PNGHandler : public ImageHandler { public: virtual bool vfunc_8(int); };
bool PNGHandler::vfunc_8(int x) { return x == 1; }