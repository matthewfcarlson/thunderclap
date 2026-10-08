class HalStream { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); };
namespace audio {
class OmHalStream : public HalStream { public: char pad[0xb0]; void* vfunc_9(int); };
void* OmHalStream::vfunc_9(int param_2) { return (char*)this + param_2 * 16 + 0xb4; }
}