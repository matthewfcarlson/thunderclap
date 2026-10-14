// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_00189d50 @ 0x00189d50
typedef unsigned int size_t;
inline void* operator new(size_t, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void FUN_0017f550(); void FUN_0017f570(); void FUN_0017f580();
extern int DAT_00427758, DAT_00427760, DAT_004e1438, DAT_004e143c;
namespace hulkfight { namespace motion { class PropStateByNameCondition; } }
struct IntBase_189d50 { char data[24]; void FUN_002348e0(const char*); };
struct EnumBase_189d50 { char data[32]; void FUN_00234cc0(const char*); };
struct NameBase_189d50 { char data[24]; void FUN_00234a90(const char*); };
namespace fight {
template<class T> struct ParamIntConstRange { virtual void slot0(); char pad[12]; void (*callback)(); int tail; };
template<class T> struct ParamEnumConstList { virtual void slot0(); char pad[12]; int* list; int count; void (*callback)(); int tail; };
template<class T> struct ParamName { virtual void slot0(); char pad[12]; void (*callback)(); int tail; };
}
void __cdecl FUN_002347b0(int*,void**,int);
void FUN_00189d50() {
 if (!DAT_004e143c) {
 void* p[3];
 void* a=FUN_0008d690(24);
 if(a) { ((IntBase_189d50*)a)->FUN_002348e0("attachmentIndex"); fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>* obj=new(a) fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>; obj->callback=FUN_0017f550; }
 p[0]=a;
 void* b=FUN_0008d690(32);
 if(b) { int n=DAT_00427760; ((EnumBase_189d50*)b)->FUN_00234cc0("compare"); fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>* obj=new(b) fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>; obj->count=n; obj->list=&DAT_00427758; obj->callback=FUN_0017f570; }
 p[1]=b;
 void* c=FUN_0008d690(24);
 if(c) { ((NameBase_189d50*)c)->FUN_00234a90("state"); fight::ParamName<hulkfight::motion::PropStateByNameCondition>* obj=new(c) fight::ParamName<hulkfight::motion::PropStateByNameCondition>; obj->callback=FUN_0017f580; }
 p[2]=c;
 FUN_002347b0(&DAT_004e1438,p,3);
 }
 ++DAT_004e143c;
}