// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 8/8)
// FUN_0016b7c0 @ 0x0016b7c0
typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* p) { return p; }
extern void* __cdecl FUN_0008d690(unsigned int);
extern unsigned int DAT_004e125c;
extern unsigned int DAT_004e1258;
extern unsigned int DAT_00427754;
extern char DAT_0042773c[];
extern char DAT_004b4d88[];
void FUN_00165710(); void FUN_00165720(); void FUN_00165730();
struct ParamBase_16b7c0 { virtual void slot0(); char padding[12]; void FUN_00234cc0(const char*); void FUN_00234960(const char*); };
namespace hulkfight { namespace motion { class GrappleHealthCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList : ParamBase_16b7c0 { virtual void slot0(); const char* values; unsigned int count; void (*callback)(); unsigned int tail; };
template<class T> struct ParamFloatConstRange : ParamBase_16b7c0 { virtual void slot0(); void (*callback)(); unsigned int tail; };
}
extern void __cdecl FUN_002347b0(unsigned int*, ParamBase_16b7c0**, unsigned int);
void __cdecl FUN_0016b7c0() {
 if (!DAT_004e125c) {
  ParamBase_16b7c0* params[3];
  void* mem = FUN_0008d690(32);
  if(mem) {
   unsigned int count = DAT_00427754;
   ((ParamBase_16b7c0*)mem)->FUN_00234cc0("compare");
   fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>* p = new(mem) fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>;
   p->count=count; p->values=DAT_0042773c; p->callback=FUN_00165710; params[0]=p;
  } else params[0]=0;
  mem=FUN_0008d690(24);
  if(mem) {
   ((ParamBase_16b7c0*)mem)->FUN_00234960("health");
   fight::ParamFloatConstRange<hulkfight::motion::GrappleHealthCondition>* p = new(mem) fight::ParamFloatConstRange<hulkfight::motion::GrappleHealthCondition>;
   p->callback=FUN_00165720; params[1]=p;
  } else params[1]=0;
  mem=FUN_0008d690(32);
  if(mem) {
   ((ParamBase_16b7c0*)mem)->FUN_00234cc0("constant");
   fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>* p = new(mem) fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>;
   p->values=DAT_004b4d88; p->count=4; p->callback=FUN_00165730; params[2]=p;
  } else params[2]=0;
  FUN_002347b0(&DAT_004e1258,params,3);
 }
 ++DAT_004e125c;
}
