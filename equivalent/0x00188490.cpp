// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 8/8)
// FUN_00188490 @ 0x00188490
#include "decls/data/game/hulkfight/motion.h"

void FUN_00180340();
void FUN_00180360();
void FUN_00180380();
namespace hulkfight { namespace motion { class PropAddToCollisionTrack; } }
struct FUN_0008d690 { static void* __cdecl operator new(unsigned int) throw(); };
struct FUN_00234960 : FUN_0008d690 {
 FUN_00234960(const char* = "timeBegin") throw();
 virtual void slot0();
 char data[12];
 void (*callback)();
 int tail;
};
struct FUN_002348e0 : FUN_0008d690 {
 FUN_002348e0(const char* = "attachmentIndex") throw();
 virtual void slot0();
 char data[12];
 void (*callback)();
 int tail;
};
struct FUN_00234860 : FUN_0008d690 {
 FUN_00234860(const char* = "addMissile") throw();
 virtual void slot0();
 char data[12];
 void (*callback)();
 int tail;
};
namespace fight {
 template<class T> struct ParamFloatConstRange : FUN_00234960 { virtual void slot0(); };
 template<class T> struct ParamIntConstRange : FUN_002348e0 { virtual void slot0(); };
 template<class T> struct ParamBool : FUN_00234860 { virtual void slot0(); };
}
void __cdecl FUN_002347b0(void*,void**,int);
void __cdecl FUN_00188490() {
 if (!DAT_004e14cc) {
 void* params[3];
 fight::ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>* a=new fight::ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>;
 if(a) a->callback=FUN_00180340;
 params[0]=a;
 fight::ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>* b=new fight::ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>;
 if(b) b->callback=FUN_00180360;
 params[1]=b;
 fight::ParamBool<hulkfight::motion::PropAddToCollisionTrack>* c=new fight::ParamBool<hulkfight::motion::PropAddToCollisionTrack>;
 if(c) c->callback=FUN_00180380;
 params[2]=c;
 FUN_002347b0(&DAT_004e14c8,params,3);
 }
 ++DAT_004e14cc;
}
