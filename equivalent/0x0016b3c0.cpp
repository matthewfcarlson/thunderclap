// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_0016b3c0 @ 0x0016b3c0
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern int DAT_004e1224;
extern int DAT_004e1220;
extern int DAT_00427760;
extern int DAT_003f5bbc;
extern int DAT_00427758;
extern int DAT_0048f590;
extern void FUN_00165580();
extern void FUN_00165590();
extern void* __cdecl FUN_0008d690(unsigned int);
namespace hulkfight { namespace motion { class LocomotionMotionStateCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char padding[12];
 int* values;
 int count;
 void (*callback)();
 int tail;
 void FUN_00234cc0(const char*);
};
}
typedef fight::ParamEnumConstList<hulkfight::motion::LocomotionMotionStateCondition> List;
extern void __cdecl FUN_002347b0(int*, List**, int);
void initialize() {
 if (!DAT_004e1224) {
  List* lists[2];
  List* a = (List*)FUN_0008d690(32);
  if (a) {
   int count = DAT_00427760;
   a->FUN_00234cc0("compare");
   new(a) List;
   a->values = &DAT_00427758;
   a->count = count;
   a->callback = FUN_00165580;
  }
  lists[0] = a;
  List* b = (List*)FUN_0008d690(32);
  if (b) {
   int count = DAT_003f5bbc;
   b->FUN_00234cc0("locomotionMotionState");
   new(b) List;
   b->values = &DAT_0048f590;
   b->count = count;
   b->callback = FUN_00165590;
  }
  lists[1] = b;
  FUN_002347b0(&DAT_004e1220, lists, 2);
 }
 ++DAT_004e1224;
}
