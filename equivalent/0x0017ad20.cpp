// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_0017ad20 @ 0x0017ad20
inline void* operator new(unsigned int, void* storage) { return storage; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0016fa00(); void __cdecl FUN_00170de0(); void __cdecl FUN_0016fa40();
namespace hulkfight { namespace motion { class TeleportToLocatorTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00234960(const char*); };
template<class T> struct ParamString { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); char tail[4]; void FUN_002349e0(const char*); };
template<class T> struct ParamVector { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00234e50(const char*); };
}
extern unsigned int DAT_004e13a4; extern unsigned int DAT_004e13a0;
void __cdecl FUN_002347b0(void*, void**, int);
void FUN_0017ad20() {
 if (!DAT_004e13a4) {
 void* params[3]; typedef hulkfight::motion::TeleportToLocatorTrack Track;
 fight::ParamFloatConstRange<Track>* a = (fight::ParamFloatConstRange<Track>*)FUN_0008d690(24);
 if(a) { a->FUN_00234960("timeBegin"); new(a) fight::ParamFloatConstRange<Track>; a->callback=FUN_0016fa00; } params[0]=a;
 fight::ParamString<Track>* b = (fight::ParamString<Track>*)FUN_0008d690(24);
 if(b) { b->FUN_002349e0("text"); new(b) fight::ParamString<Track>; b->callback=FUN_00170de0; } params[1]=b;
 fight::ParamVector<Track>* c = (fight::ParamVector<Track>*)FUN_0008d690(24);
 if(c) { c->FUN_00234e50("offset"); new(c) fight::ParamVector<Track>; c->callback=FUN_0016fa40; } params[2]=c;
 FUN_002347b0(&DAT_004e13a0,params,3);
 }
 ++DAT_004e13a4;
}