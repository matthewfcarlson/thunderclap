// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// hulkfight::motion::AnimationPhaseMatchedAction::vfunc_5 @ 0x0013af20
struct Controller;
struct Context { Controller* FUN_000592a0(); };
struct Entries;
struct Controller { Entries* FUN_00059a40(); };
struct Entries { char pad[0x68]; unsigned count; void* FUN_00222e20(unsigned); };
struct Phase { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(int); char pad[0x1c]; float duration; float phase; };
struct Animation { char pad[0x228]; float speed; float start; float end; float FUN_00225ab0(); void FUN_00225cf0(float); };
struct Offset { char pad[0x20]; float value; };
extern int DAT_0048d534; extern int DAT_004ac1d0;
void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
float __cdecl FUN_0004af40(float,float,float);
namespace hulkfight { namespace motion {
struct AnimationPhaseMatchedAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int,int);
 char pad[0x18]; Offset* offset; Context* context; Animation* animation;
};
bool AnimationPhaseMatchedAction::vfunc_5(int flag,int unused) {
 if(flag) return true;
 if(!context) return false;
 Entries* entries=context->FUN_000592a0()->FUN_00059a40();
 if(!entries) return false;
 for(unsigned i=0;i<entries->count;++i) {
 Phase* phase=(Phase*)FUN_00344e74(entries->FUN_00222e20(i),0,&DAT_0048d534,&DAT_004ac1d0,0);
 if(!phase) continue;
 phase->v9(0);
 float duration=phase->duration;
 if(duration>0.0f) {
 float scale=animation->FUN_00225ab0();
 animation->speed=scale*animation->speed/duration;
 }
 float start=animation->start;
 float end=animation->end;
 float value=(end-start)*phase->phase+offset->value;
 float result=FUN_0004af40(start,end,value);
 animation->FUN_00225cf0(result);
 break;
 }
 return true;
}
}}
