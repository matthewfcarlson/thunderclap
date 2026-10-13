// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 8/8)
// FUN_001558e0 @ 0x001558e0
inline void* __cdecl operator new(unsigned int, void* memory) { return memory; }
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void FUN_0014c640(); extern "C" void FUN_0014c660(); extern "C" void FUN_0014c680();
extern int DAT_00427754, DAT_004e10a4, DAT_004e10a0;
namespace hulkfight { namespace motion { class CollisionChargeCondition; } }
struct BaseEnum { virtual void slot(); char pad[12]; const char* list; int count; void (*callback)(); int tail; void FUN_00234cc0(const char*); };
struct BaseFloat { virtual void slot(); char pad[12]; void (*callback)(); int tail; void FUN_00234960(const char*); };
struct BaseBool { virtual void slot(); char pad[12]; void (*callback)(); int tail; void FUN_00234860(const char*); };
namespace fight {
template<class T> struct ParamEnumConstList : BaseEnum { virtual void slot(); };
template<class T> struct ParamFloatConstRange : BaseFloat { virtual void slot(); };
template<class T> struct ParamBool : BaseBool { virtual void slot(); };
}
typedef fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition> Enum;
typedef fight::ParamFloatConstRange<hulkfight::motion::CollisionChargeCondition> Float;
typedef fight::ParamBool<hulkfight::motion::CollisionChargeCondition> Bool;
extern "C" void __cdecl FUN_002347b0(int*, void**, int);
void target() {
 if (!DAT_004e10a4) {
  void* objects[3];
  Enum* p=(Enum*)FUN_0008d690(32);
  if(p) { int count=DAT_00427754; p->FUN_00234cc0("compare"); p->count=count; new(p) Enum; p->list="lwB"; p->callback=FUN_0014c640; }
  objects[0]=p;
  Float* f=(Float*)FUN_0008d690(24);
  if(f) { f->FUN_00234960("charge"); new(f) Float; f->callback=FUN_0014c660; } objects[1]=f;
  Bool* b=(Bool*)FUN_0008d690(24);
  if(b) { b->FUN_00234860("useArmorValue"); new(b) Bool; b->callback=FUN_0014c680; } objects[2]=b;
  FUN_002347b0(&DAT_004e10a0,objects,3);
 }
 ++DAT_004e10a4;
}
