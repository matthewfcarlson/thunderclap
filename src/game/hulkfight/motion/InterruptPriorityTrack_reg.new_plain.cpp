// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154c00..0x00156e80 (kind game, layer game, confidence high), dominant class hulkfight::motion::InterruptPriorityTrack
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f8a523c5 {
#define TREE_TU_END }
namespace fn_f8a523c5 {} using namespace fn_f8a523c5;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* memory) { return memory; }
namespace fn_f8a523c5 {
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void SetCompare_0014c640();
extern "C" void SetCharge_0014c660();
extern "C" void SetUseArmorValue_0014c680();
} // namespace fn_f8a523c5
namespace hulkfight { namespace motion {
class CollisionChargeCondition_1558e0;
} }
namespace fn_f8a523c5 {
struct BaseEnum_1558e0 { virtual void slot(); char pad[12]; const char* list; int count; void (*callback)(); int tail; void FUN_00234cc0(const char*); };
struct BaseFloat_1558e0 { virtual void slot(); char pad[12]; void (*callback)(); int tail;  };
struct BaseBool { virtual void slot(); char pad[12]; void (*callback)(); int tail;  };
} // namespace fn_f8a523c5
namespace fight {
template<class T> struct ParamEnumConstList_1558e0 : BaseEnum_1558e0 { virtual void slot(); };
}
namespace fight {
template<class T> struct ParamFloatConstRange_1558e0 : BaseFloat_1558e0 { virtual void slot(); };
}
namespace fight {
template<class T> struct ParamBool_1558e0 : BaseBool { virtual void slot(); };
}
namespace fn_f8a523c5 {
typedef fight::ParamEnumConstList_1558e0<hulkfight::motion::CollisionChargeCondition_1558e0> Enum_1558e0;
typedef fight::ParamFloatConstRange_1558e0<hulkfight::motion::CollisionChargeCondition_1558e0> Float_1558e0;
typedef fight::ParamBool_1558e0<hulkfight::motion::CollisionChargeCondition_1558e0> Bool_1558e0;
extern "C" void __cdecl FUN_002347b0(int*, void**, int);

} // namespace fn_f8a523c5

// 0x00155270 FUN_00155270 (192 B): matches/0x00155270.cpp [wrapped: conflict: fight::ParamEnumConstList]
// sym: _FUN_00155270
namespace fn_00155270 {


extern void SetCompare_0014c4d0();
extern void SetSize_0014c4e0();
extern void* __cdecl FUN_0008d690(unsigned int);
namespace hulkfight {
namespace motion {
class CollisionSourceSizeCondition;
}
} // namespace hulkfight
struct Base_155270 {
    virtual void slot0();
    char pad[12];
    void FUN_00234cc0(const char*);
};
namespace fight {
template <class T> struct ParamEnumConstList : Base_155270 {
    virtual void slot0();
    void* entries;
    unsigned int count;
    void (*callback)();
    unsigned int tail;
};
} // namespace fight
typedef fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition> Param;
extern void __cdecl FUN_002347b0(void*, Param**, unsigned int);
extern "C" void FUN_00155270() {
    if (DAT_004e1044 == 0) {
        Param* params[2];
        void* mem = FUN_0008d690((int)sizeof(Param));
        if (mem) {
            unsigned int count = (*(unsigned int*)&DAT_00427760);
            Base_155270* base = (Base_155270*)mem;
            base->FUN_00234cc0("compare");
            Param* p = new (mem) Param;
            p->entries = ((char*)&DAT_00427758);
            p->count = count;
            p->callback = SetCompare_0014c4d0;
            params[0] = p;
        } else
            params[0] = 0;
        mem = FUN_0008d690((int)sizeof(Param));
        if (mem) {
            unsigned int count = (*(unsigned int*)&DAT_003f5eb4);
            Base_155270* base = (Base_155270*)mem;
            base->FUN_00234cc0("size");
            Param* p = new (mem) Param;
            p->entries = ((char*)&DAT_0048f6b4);
            p->count = count;
            p->callback = SetSize_0014c4e0;
            params[1] = p;
        } else
            params[1] = 0;
        FUN_002347b0(((unsigned int*)&DAT_004e1040), params, 2);
    }
    ++DAT_004e1044;
}
} // namespace fn_00155270


// 0x00155330 FUN_00155330 (190 B): equivalent/0x00155330.cpp [wrapped: conflict: Param; fight::ParamEnumConstList]
// sym: _FUN_00155330 @d3b16e9e0c8f @wab1c64862edc
namespace fn_00155330 {
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00155330 @ 0x00155330


extern void SetCompare_0014c4f0();
extern void SetType_0014c500();
extern void* __cdecl FUN_0008d690(unsigned int);
struct Base_155330 { void FUN_00234cc0(const char*); };
namespace hulkfight { namespace motion { class CollisionSourceTypeCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char padding[12];
 void* values;
 int count;
 void (*callback)();
 int tail;
};
}
typedef fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition> Param;
extern void __cdecl FUN_002347b0(int*, Param**, int);
extern "C" void FUN_00155330() {
 if (DAT_004e104c == 0) {
  Param* params[2];
  void* storage = FUN_0008d690((int)sizeof(Param));
  if (storage) {
   int count = (*(int*)&DAT_00427760);
   ((Base_155330*)storage)->FUN_00234cc0("compare");
   Param* p = new (storage) Param;
   p->count = count;
   p->values = ((char*)&DAT_00427758);
   p->callback = &SetCompare_0014c4f0;
   params[0] = p;
  } else params[0] = 0;
  storage = FUN_0008d690((int)sizeof(Param));
  if (storage) {
   ((Base_155330*)storage)->FUN_00234cc0("type");
   Param* p = new (storage) Param;
   p->values = ((char*)&DAT_004af9f0);
   p->count = 2;
   p->callback = &SetType_0014c500;
   params[1] = p;
  } else params[1] = 0;
  FUN_002347b0(&DAT_004e1048, params, 2);
 }
 ++DAT_004e104c;
}
} // namespace fn_00155330


// 0x001555c0 FUN_001555c0 (192 B): matches/0x001555c0.cpp [wrapped: conflict: fight::ParamEnumConstList]
// sym: _FUN_001555c0
namespace fn_001555c0 {

typedef unsigned int uint;
void* __cdecl FUN_0008d690(uint);
void SetCompare_0014c580();
void SetSize_0014c590();

namespace hulkfight {
namespace motion {
class CollisionTargetSizeCondition;
}
} // namespace hulkfight
namespace fight {
template <class T> struct ParamEnumConstList {
    virtual void slot0();
    char padding[12];
    void* values;
    uint count;
    void (*callback)();
    uint tail;
    void FUN_00234cc0(const char*);
};
} // namespace fight
typedef fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition> List_1555c0;
void __cdecl FUN_002347b0(uint*, List_1555c0**, int);
extern "C" void __cdecl FUN_001555c0() {
    if (!(*(uint*)&DAT_004e1074)) {
        List_1555c0* lists[2];
        void* memory = FUN_0008d690((int)sizeof(List_1555c0));
        if (memory) {
            List_1555c0* p = (List_1555c0*)memory;
            uint count = (*(uint*)&DAT_00427760);
            p->FUN_00234cc0("compare");
            p = new (memory) List_1555c0;
            p->values = ((uint*)&DAT_00427758);
            p->count = count;
            p->callback = SetCompare_0014c580;
            lists[0] = p;
        } else
            lists[0] = 0;
        memory = FUN_0008d690((int)sizeof(List_1555c0));
        if (memory) {
            List_1555c0* p = (List_1555c0*)memory;
            uint count = (*(uint*)&DAT_003f5eb4);
            p->FUN_00234cc0("size");
            p = new (memory) List_1555c0;
            p->values = ((uint*)&DAT_0048f6b4);
            p->count = count;
            p->callback = SetSize_0014c590;
            lists[1] = p;
        } else
            lists[1] = 0;
        FUN_002347b0(((uint*)&DAT_004e1070), lists, 2);
    }
    ++(*(uint*)&DAT_004e1074);
}
} // namespace fn_001555c0


// 0x001557f0 FUN_001557f0 (231 B): equivalent/0x001557f0.cpp [wrapped: conflict: fight::ParamBool; fight::ParamBranch; fight::ParamEnumConstList]
// sym: ?target@fn_001557f0@@YAXXZ @04be5aafdb45 @w7c0d541b4eaf
namespace fn_001557f0 {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_001557f0 @ 0x001557f0


void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetCompare_0014c610(); void __cdecl GetBranch_0014c620(); void __cdecl SetCheckAncestors_0014c630();
namespace hulkfight { namespace motion { class CollisionSourceNodeCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList { virtual void slot0(); char pad[12]; unsigned int* values; unsigned int count; void (__cdecl *callback)(); unsigned int extra; void FUN_00234cc0(const char*); };
template<class T> struct ParamBranch { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); unsigned int extra; void FUN_00235170(const char*); };
template<class T> struct ParamBool { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); unsigned int extra; void FUN_00234860(const char*); };
}
void __cdecl FUN_002347b0(unsigned int*, void**, int);
void target() {
 if (!(*(unsigned int*)&DAT_004e109c)) {
 void* params[3]; typedef hulkfight::motion::CollisionSourceNodeCondition Node;
 fight::ParamEnumConstList<Node>* a=(fight::ParamEnumConstList<Node>*)FUN_0008d690((int)sizeof(fight::ParamEnumConstList<Node>));
 if(a) { unsigned int count=(*(unsigned int*)&DAT_00427760); a->FUN_00234cc0("compare"); a->count=count; new(a) fight::ParamEnumConstList<Node>; a->values=((unsigned int*)&DAT_00427758); a->callback=SetCompare_0014c610; } params[0]=a;
 fight::ParamBranch<Node>* b=(fight::ParamBranch<Node>*)FUN_0008d690((int)sizeof(fight::ParamBranch<Node>));
 if(b) { b->FUN_00235170("branch"); new(b) fight::ParamBranch<Node>; b->callback=GetBranch_0014c620; } params[1]=b;
 fight::ParamBool<Node>* c=(fight::ParamBool<Node>*)FUN_0008d690((int)sizeof(fight::ParamBool<Node>));
 if(c) { c->FUN_00234860("checkAncestors"); new(c) fight::ParamBool<Node>; c->callback=SetCheckAncestors_0014c630; } params[2]=c;
 FUN_002347b0(((unsigned int*)&DAT_004e1098),params,3);
 } ++(*(unsigned int*)&DAT_004e109c);
}
} // namespace fn_001557f0

namespace fn_f8a523c5 {

// 0x001558e0 FUN_001558e0 (231 B): equivalent/0x001558e0.cpp
// sym: ?target@fn_f8a523c5@@YAXXZ @cb332813ee9c @w11641f4868d0
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 8/8)
// FUN_001558e0 @ 0x001558e0
void target() {
 if (!(*(int*)&DAT_004e10a4)) {
  void* objects[3];
  Enum_1558e0* p=(Enum_1558e0*)FUN_0008d690((int)sizeof(Enum_1558e0));
  if(p) { int count=(*(int*)&DAT_00427754); p->FUN_00234cc0("compare"); p->count=count; new(p) Enum_1558e0; p->list="lwB"; p->callback=SetCompare_0014c640; }
  objects[0]=p;
  Float_1558e0* f=(Float_1558e0*)FUN_0008d690((int)sizeof(Float_1558e0));
  if(f) { ((fight::ParamValueFloat *)(BaseFloat_1558e0 *)f)->FUN_00234960("charge"); new(f) Float_1558e0; f->callback=SetCharge_0014c660; } objects[1]=f;
  Bool_1558e0* b=(Bool_1558e0*)FUN_0008d690((int)sizeof(Bool_1558e0));
  if(b) { ((fight::ParamValueBool *)(BaseBool *)b)->FUN_00234860("useArmorValue"); new(b) Bool_1558e0; b->callback=SetUseArmorValue_0014c680; } objects[2]=b;
  FUN_002347b0(((int*)&DAT_004e10a0),objects,3);
 }
 ++(*(int*)&DAT_004e10a4);
}

} // namespace fn_f8a523c5
