typedef unsigned char byte;
class Sub { public: void f(); };
class Base { public: void g(); };
extern void cdel(void*);
extern int vftable;
class AnimationChargeTrack {
public:
 int vf;
 char pad1[0x18-4];
 Sub a;
 char pad2[0x28-0x18-1];
 Sub b;
 AnimationChargeTrack* vfunc_5(byte param);
};
AnimationChargeTrack* AnimationChargeTrack::vfunc_5(byte param) {
 vf = (int)&vftable;
 b.f();
 a.f();
 ((Base*)this)->g();
 if (param & 1) cdel(this);
 return this;
}
