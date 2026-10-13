// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 10/10)
// FUN_00112d30 @ 0x00112d30
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0010c600(); void __cdecl FUN_0010c610(); void __cdecl FUN_0010c620(); void __cdecl FUN_0010c630();
namespace hulkfight { namespace ai { class AIHistorySetTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange { virtual void slot0(); char data[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00234960(const char*); };
template<class T> struct ParamBool { virtual void slot0(); char data[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00234860(const char*); };
template<class T> struct ParamName { virtual void slot0(); char data[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00234a90(const char*); };
}
extern unsigned int DAT_004e0b94, DAT_004e0b90;
void __cdecl FUN_002347b0(void*, void**, int);
void target() {
 if (DAT_004e0b94 == 0) {
 void* items[4];
 typedef fight::ParamFloatConstRange<hulkfight::ai::AIHistorySetTrack> FloatParam;
 typedef fight::ParamBool<hulkfight::ai::AIHistorySetTrack> BoolParam;
 typedef fight::ParamName<hulkfight::ai::AIHistorySetTrack> NameParam;
 FloatParam* a=(FloatParam*)FUN_0008d690(24);
 if(a) { a->FUN_00234960("timeBegin"); new(a) FloatParam; a->callback=FUN_0010c600; } items[0]=a;
 a=(FloatParam*)FUN_0008d690(24);
 if(a) { a->FUN_00234960("timeEnd"); new(a) FloatParam; a->callback=FUN_0010c610; } items[1]=a;
 BoolParam* b=(BoolParam*)FUN_0008d690(24);
 if(b) { b->FUN_00234860("onlySetAtEnd"); new(b) BoolParam; b->callback=FUN_0010c620; } items[2]=b;
 NameParam* c=(NameParam*)FUN_0008d690(24);
 if(c) { c->FUN_00234a90("text"); new(c) NameParam; c->callback=FUN_0010c630; } items[3]=c;
 FUN_002347b0(&DAT_004e0b90,items,4);
 }
 ++DAT_004e0b94;
}
