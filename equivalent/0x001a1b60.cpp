// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 8/8)
// FUN_001a1b60 @ 0x001a1b60
inline void* operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_001a1290();
void __cdecl FUN_001a12a0();
void __cdecl FUN_001a1460();
namespace hulkfight { namespace scenario { class LuaTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_00234960(const char*);
};
template<class T> struct ParamScript {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_00234c00(const char*);
};
}
extern int DAT_004e1700;
extern int DAT_004e16fc;
void __cdecl FUN_002347b0(int*, void**, int);
void FUN_001a1b60() {
 if (!DAT_004e1700) {
 void* items[3];
 typedef fight::ParamFloatConstRange<hulkfight::scenario::LuaTrack> FloatParam;
 typedef fight::ParamScript<hulkfight::scenario::LuaTrack> ScriptParam;
 FloatParam* a = (FloatParam*)FUN_0008d690(24);
 if(a) { a->FUN_00234960("timeBegin"); new (a) FloatParam; a->callback = FUN_001a1290; }
 items[0] = a;
 FloatParam* b = (FloatParam*)FUN_0008d690(24);
 if(b) { b->FUN_00234960("timeEnd"); new (b) FloatParam; b->callback = FUN_001a12a0; }
 items[1] = b;
 ScriptParam* c = (ScriptParam*)FUN_0008d690(24);
 if(c) { c->FUN_00234c00("script"); new (c) ScriptParam; c->callback = FUN_001a1460; }
 items[2] = c;
 FUN_002347b0(&DAT_004e16fc, items, 3);
 }
 ++DAT_004e1700;
}
