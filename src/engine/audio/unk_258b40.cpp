// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00258b40..0x00258e50 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fc3d66b3 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc3d66b3 {} using namespace fn_fc3d66b3;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fc3d66b3 {
class C_258b40 {
    char pad[0x1c];

  public:
    unsigned char value;
};
struct Item {
  public:
    char _m_pad_0[0x10];
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    char _m_pad_20[0x58];
    int value;
};
struct Owner {
  public:
    char _m_pad_0[0x20];
    Item* items[1];
};
struct Obj_258b80 {
    char pad[0x14];
    float value;
};
struct Entry { unsigned a,b,c,d; unsigned index; };
struct Target_258bf0 { char pad[0x20]; int value; };
struct Table_258bf0 { char pad[0x20]; Target_258bf0* slot[1]; };
struct Pair_258bf0 { int value; int index; };
class X_258c80 {
  public:
    char pad[0x10];
    float value;
};


// 0x00258b40 FUN_00258b40 (12 B): matches/0x00258b40.cpp
// sym: _FUN_00258b40
extern "C" void __cdecl FUN_00258b40(C_258b40* self, unsigned char value) {
    self->value = value;
}


// 0x00258b60 FUN_00258b60 (16 B): matches/0x00258b60.cpp
// sym: ?FUN_00258b60@fn_fc3d66b3@@YAHPAUOwner@1@H@Z
int __cdecl FUN_00258b60(Owner* p, int index) {
    return p->items[index]->value;
}


// 0x00258b70 FUN_00258b70 (8 B): matches/0x00258b70.cpp
// sym: _FUN_00258b70
extern "C" int __cdecl FUN_00258b70(char* object) {
    return *(int*)(object + 0x60);
}


// 0x00258b80 FUN_00258b80 (12 B): matches/0x00258b80.cpp
// sym: _FUN_00258b80
extern "C" void FUN_00258b80(Obj_258b80* p, float value) {
    p->value = value;
}


// 0x00258ba0 FUN_00258ba0 (74 B): equivalent/0x00258ba0.cpp
// sym: _FUN_00258ba0
// STATUS: equivalent (tools/equiv.py level 3: 129 inputs, branch coverage 4/4)
// FUN_00258ba0 @ 0x00258ba0
extern "C" void __cdecl FUN_00258ba0(Owner* owner, Entry* entries, unsigned count) { for (unsigned i=0; i<count; ++i) { Item* item=owner->items[entries[i].index]; item->a=entries[i].a; item->b=entries[i].b; item->c=entries[i].c; item->d=entries[i].d; } }


// 0x00258bf0 FUN_00258bf0 (137 B): equivalent/0x00258bf0.cpp
// sym: ?ApplyPairs@fn_fc3d66b3@@YAXPAUTable_258bf0@1@PAUPair_258bf0@1@I@Z
// STATUS: equivalent (tools/equiv.py level 3: 129 inputs, branch coverage 8/8)
// FUN_00258bf0 @ 0x00258bf0
void __cdecl ApplyPairs(Table_258bf0* table, Pair_258bf0* pairs, unsigned count) {
    for (unsigned i = 0; i < count; i++)
        table->slot[pairs[i].index]->value = pairs[i].value;
}


// 0x00258c80 FUN_00258c80 (28 B): matches/0x00258c80.cpp
// sym: _FUN_00258c80
extern "C" void FUN_00258c80(X_258c80* x, float v) {
    if (x->value != v)
        x->value = v;
}


// 0x00258cb0 FUN_00258cb0 (13 B): matches/0x00258cb0.cpp
// sym: _FUN_00258cb0
extern "C" int __cdecl FUN_00258cb0(int* object, int index) {
    return object[index + 25];
}

} // namespace fn_fc3d66b3
