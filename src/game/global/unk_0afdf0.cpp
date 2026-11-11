// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000afdf0..0x000b0060 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7328a2c {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7328a2c {} using namespace fn_f7328a2c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f7328a2c {
class Other_afe10 {
  public:
    void Run(int);
};
class Thing_afe10 {
  public:
    char pad[5];
    unsigned char flag;
    Other_afe10* p;
    void Set(int);
};
class CKeyPoseTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual float vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
};
struct Child_afe80 {
    void cleanup();
};
struct Obj_afe80 {
    char pad[5];
    bool flag;
    char pad2[2];
    Child_afe80* ptr;
    void run();
};
struct Node {
    char pad[0x10];
    int count;
    void F530(int, int, float);
};
struct Holder_afea0 {
    char pad[8];
    Node* nodes[1];
    void Set(int idx, float a, float b, float c);
};
struct Entry_aff30 { char pad[20]; char name[1]; };
struct Entries_aff30 {  };
struct Group_aff30 {
 char pad[12]; Entries_aff30* entries; int count;
 void FUN_000af530(int index,int channel,float value);
 void FUN_000af650(int index,int channel,int value);
};
struct Owner_aff30 {
 char pad[8]; Group_aff30* groups[1];
 void update(int slot,float first,float second,int value,const char* name);
};
class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
};

} // namespace fn_f7328a2c

// 0x000afdf0 FUN_000afdf0 (12 B): matches/0x000afdf0.cpp
// sym: ?FUN_000afdf0@A_afdf0@owners@@QAEXXZ
void owners::A_afdf0::FUN_000afdf0() {
    if (!flag)
        flag = 1;
}

namespace fn_f7328a2c {

// 0x000afe10 FUN_000afe10 (34 B): matches/0x000afe10.cpp
// sym: ?Set@Thing_afe10@fn_f7328a2c@@QAEXH@Z
void Thing_afe10::Set(int value) {
    if (flag != (unsigned char)value) {
        if (p)
            p->Run(value);
        flag = (unsigned char)value;
    }
}

} // namespace fn_f7328a2c

// 0x000afe40 FUN_000afe40 (25 B): matches/0x000afe40.cpp
// sym: ?FUN_000afe40@C_afe40@owners@@QAEHH@Z
hulk_intptr owners::C_afe40::FUN_000afe40(int i) {
    if (i < 0 || i >= 1)
        return 0;
    return pad[2 + i];
}

namespace fn_f7328a2c {

// 0x000afe60 FUN_000afe60 (7 B): matches/0x000afe60.cpp
// sym: ?vfunc_7@CKeyPoseTrack@fn_f7328a2c@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
float CKeyPoseTrack::vfunc_7() {
    return DAT_003f32dc;
}

} // namespace fn_f7328a2c

// 0x000afe70 FUN_000afe70 (7 B): matches/0x000afe70.cpp [wrapped: same definition as 0x000afe60 in this TU]
// sym: ?vfunc_7@CKeyPoseTrack@fn_000afe70@@UAEMXZ
namespace fn_000afe70 {
// Same code shape as 0x000695a0 (propagated; names are from that function)

class CKeyPoseTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual float vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
};

float CKeyPoseTrack::vfunc_7() {
    return DAT_003f32dc;
}
} // namespace fn_000afe70

namespace fn_f7328a2c {

// 0x000afe80 FUN_000afe80 (29 B): matches/0x000afe80.cpp
// sym: ?run@Obj_afe80@fn_f7328a2c@@QAEXXZ
void Obj_afe80::run() {
    if (ptr)
        ptr->cleanup();
    if (flag)
        FUN_002684c0();
}


// 0x000afea0 FUN_000afea0 (133 B): matches/0x000afea0.cpp
// sym: ?Set@Holder_afea0@fn_f7328a2c@@QAEXHMMM@Z
void Holder_afea0::Set(int idx, float a, float b, float c) {
    if (idx < 0 || idx >= 1)
        return;
    Node* n = nodes[idx];
    if (!n)
        return;
    int i = 0;
    if (n->count > 0) {
        float x = a * 0.01f;
        float y = b * 0.01f;
        do {
            n->F530(i, 0, x);
            n->F530(i, 1, y);
            ((owners::Obj_af650 *)n)->FUN_000af650(i, 0, c);
            ((owners::Obj_af650 *)n)->FUN_000af650(i, 1, c);
            i++;
        } while (i < n->count);
    }
}


// 0x000aff30 FUN_000aff30 (203 B): equivalent/0x000aff30.cpp
// sym: ?update@Owner_aff30@fn_f7328a2c@@QAEXHMMHPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 20/20)
// FUN_000aff30 @ 0x000aff30
void Owner_aff30::update(int slot,float first,float second,int value,const char* name) {
 if(slot < 0 || slot >= 1) return;
 Group_aff30* group=groups[slot];
 if(!group) return;
 for(int i=0;i<group->count;++i) {
  Entry_aff30* entry=((Entry_aff30 *)((owners::C_ace20 *)(group->entries))->FUN_000ace20(i));
  const char* a=name; const char* b=entry->name;
  while(*a==*b && *a) { ++a; ++b; }
  if(*a==*b) {
   group->FUN_000af530(i,0,first*0.01f);
   group->FUN_000af530(i,1,second*0.01f);
   group->FUN_000af650(i,0,value);
   group->FUN_000af650(i,1,value);
  }
 }
}


// 0x000b0000 FUN_000b0000 (36 B): matches/0x000b0000.cpp
// sym: ?FUN_000b0000@fn_f7328a2c@@YAXPAPAVObj@1@PAV21@@Z
void FUN_000b0000(Obj** slot, Obj* value) {
    if (value)
        value->AddRef();
    if (*slot)
        (*slot)->Release();
    *slot = value;
}

} // namespace fn_f7328a2c
