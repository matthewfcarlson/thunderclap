// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 8/8)
// FUN_00129480 @ 0x00129480
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_00123a60();
void __cdecl FUN_00123a70();
void __cdecl FUN_00123a90();
extern int DAT_004e0e10;
extern int DAT_004e0e0c;
namespace hulkfight { namespace ai { class ClearProjectileDistanceTrack; } }
namespace fight {
class Base { public: virtual void slot0(); char pad[12]; void (__cdecl *callback)(); int tail; void FUN_00234960(const char*); void FUN_00234860(const char*); };
template<class T> class ParamFloatConstRange : public Base { public: virtual void slot0(); };
template<class T> class ParamBool : public Base { public: virtual void slot0(); };
}
void __cdecl FUN_002347b0(int*, fight::Base**, int);
void target() {
 if (DAT_004e0e10 == 0) {
 fight::Base* entries[3];
 void* p = FUN_0008d690(24);
 if(p) { ((fight::Base*)p)->FUN_00234960("timeBegin"); entries[0] = new(p) fight::ParamFloatConstRange<hulkfight::ai::ClearProjectileDistanceTrack>; entries[0]->callback = FUN_00123a60; } else entries[0]=0;
 p=FUN_0008d690(24);
 if(p) { ((fight::Base*)p)->FUN_00234960("timeEnd"); entries[1] = new(p) fight::ParamFloatConstRange<hulkfight::ai::ClearProjectileDistanceTrack>; entries[1]->callback = FUN_00123a70; } else entries[1]=0;
 p=FUN_0008d690(24);
 if(p) { ((fight::Base*)p)->FUN_00234860("clearEveryFrame"); entries[2] = new(p) fight::ParamBool<hulkfight::ai::ClearProjectileDistanceTrack>; entries[2]->callback = FUN_00123a90; } else entries[2]=0;
 FUN_002347b0(&DAT_004e0e0c,entries,3);
 }
 ++DAT_004e0e10;
}