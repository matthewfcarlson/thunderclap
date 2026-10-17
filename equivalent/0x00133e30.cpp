// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00133e30 @ 0x00133e30
inline void* operator new(unsigned int, void* p) { return p; }
struct Base { virtual void dummy(); char pad[4]; int enabled; int state; void FUN_00236d40(); };
struct FlyingAutoTargetTrack : Base {
 float a,b,c,d,e,f,g,h; int i,j,k;
 virtual void dummy();
 FlyingAutoTargetTrack* FUN_00133e30();
};
FlyingAutoTargetTrack* FlyingAutoTargetTrack::FUN_00133e30() {
 FUN_00236d40();
 state=0;
 new (this) FlyingAutoTargetTrack;
 a=-1.0f; b=1.57079637f; c=0.0f; d=0.0f; e=-1.0f;
 j=0; k=0; f=30.0f; g=6.28318548f; h=100.0f; i=-5;
 enabled=1;
 return this;
}