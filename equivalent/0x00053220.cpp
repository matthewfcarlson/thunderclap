// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_00053220 @ 0x00053220
extern int DAT_004dc44c;
extern int DAT_004dc448;
extern int DAT_00427760;
extern int DAT_003f5eb4;
extern char DAT_00427758;
extern char DAT_0048f6b4;
void __cdecl FUN_00047c60();
void __cdecl FUN_00047c70();
void* __cdecl FUN_0008d690(unsigned);
void __cdecl FUN_002347b0(void*,void*,int);
inline void* __cdecl operator new(unsigned,void* p) { return p; }
struct Base {
 virtual void dummy();
 char data[12];
 void FUN_00234cc0(const char*);
};
class CCharacterSizeCondition;
namespace fight {
template<class T> struct ParamEnumConstList : Base {
 virtual void dummy();
 void* values;
 int count;
 void (__cdecl *callback)();
 int tail;
};
}
void __cdecl FUN_00053220() {
 if (!DAT_004dc44c) {
  fight::ParamEnumConstList<CCharacterSizeCondition>* list[2];
  void* mem = FUN_0008d690(32);
  if(mem) {
   int count = DAT_00427760;
   Base* b=(Base*)mem;
   b->FUN_00234cc0("compare");
   list[0]=new(mem) fight::ParamEnumConstList<CCharacterSizeCondition>;
   list[0]->values=&DAT_00427758;
   list[0]->count=count;
   list[0]->callback=FUN_00047c60;
  } else list[0]=0;
  mem = FUN_0008d690(32);
  if(mem) {
   int count = DAT_003f5eb4;
   Base* b=(Base*)mem;
   b->FUN_00234cc0("size");
   list[1]=new(mem) fight::ParamEnumConstList<CCharacterSizeCondition>;
   list[1]->values=&DAT_0048f6b4;
   list[1]->count=count;
   list[1]->callback=FUN_00047c70;
  } else list[1]=0;
  FUN_002347b0(&DAT_004dc448,list,2);
 }
 ++DAT_004dc44c;
}
