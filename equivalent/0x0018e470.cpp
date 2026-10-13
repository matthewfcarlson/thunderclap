// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_0018e470 @ 0x0018e470
typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void FUN_0018cb20(); void FUN_0018cb30(); void FUN_0018cb40();
extern int DAT_00427754;
extern char DAT_004e1510;
extern int DAT_004e1514;
void __cdecl FUN_002347b0(void*, void*, int);
struct FUN_00234a90 { FUN_00234a90(const char* = "variable"); virtual void slot0(); char padding[12]; void (*callback)(); int tail; };
struct FUN_00234cc0 { FUN_00234cc0(const char* = "compare"); virtual void slot0(); char padding[12]; const char* values; int count; void (*callback)(); int tail; };
struct FUN_002348e0 { FUN_002348e0(const char* = "value"); virtual void slot0(); char padding[12]; void (*callback)(); int tail; };
namespace hulkfight { namespace motion { class GrappleVarCompareCondition; } }
namespace fight {
template<class T> struct ParamName : FUN_00234a90 { virtual void slot0(); };
template<class T> struct ParamEnumConstList : FUN_00234cc0 { virtual void slot0(); };
template<class T> struct ParamIntConstRange : FUN_002348e0 { virtual void slot0(); };
}
void target() {
 if (!DAT_004e1514) {
  void* params[3];
  typedef hulkfight::motion::GrappleVarCompareCondition T;
  void* mem = FUN_0008d690(24);
  fight::ParamName<T>* a=0;
  if (mem) { a = new(mem) fight::ParamName<T>; a->callback = FUN_0018cb20; }
  params[0]=a;
  mem=FUN_0008d690(32);
  fight::ParamEnumConstList<T>* b=0;
  if (mem) { int count = DAT_00427754; b = new(mem) fight::ParamEnumConstList<T>; b->count=count; b->values="lwB"; b->callback=FUN_0018cb30; }
  params[1]=b;
  mem=FUN_0008d690(24);
  fight::ParamIntConstRange<T>* c=0;
  if (mem) { c = new(mem) fight::ParamIntConstRange<T>; c->callback=FUN_0018cb40; }
  params[2]=c;
  FUN_002347b0(&DAT_004e1510,params,3);
 }
 ++DAT_004e1514;
}