namespace audio {
class Obj { public: virtual void f0(); virtual void f1(); };
struct Aux { void f(); };
class HalRsdFileStream { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void vfunc_12(); char pad[0x1c]; Obj* mObj; void* mValue; };
}
void FUN_00247550(void*, void*);
void audio::HalRsdFileStream::vfunc_12() {
 if (mObj) mObj->f1();
 if (mValue) FUN_00247550((void*)0x4e7b50, mValue);
 ((audio::Aux*)((char*)this+0x10))->f();
 ((audio::Aux*)((char*)this+4))->f();
 FUN_00247550((void*)0x4e7b98, this);
}