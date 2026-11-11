// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234fa0..0x00235170 (kind game, layer engine, confidence high), dominant class fight::ParamValueEntity
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0fa71c6 {
#define TREE_TU_END }
namespace fn_f0fa71c6 {} using namespace fn_f0fa71c6;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f0fa71c6 {
struct Entry_235000 { char pad00[8]; int key0; int key1; };
class ParamValueEntity {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool v6(int param, Entry_235000* entry);
    virtual Entry_235000* v7(int param, int index);
    virtual int v8(int param);
    virtual void v9();
    virtual Entry_235000* v10(int param, int key0, int key1);
};

} // namespace fn_f0fa71c6

// 0x00234fa0 fight::ParamValueEntity::vfunc_1 (6 B): matches/0x00234fa0.cpp
// sym: ?vfunc_1@ParamValueEntity@fight@@UAEHXZ
int fight::ParamValueEntity::vfunc_1() {
    return 9;
}


// 0x00234fc0 fight::ParamValueEntity::vfunc_9 (63 B): matches/0x00234fc0.cpp
// sym: ?vfunc_9@ParamValueEntity@fight@@UAEHHH@Z
int fight::ParamValueEntity::vfunc_9(int a, int b) {
    int count = vfunc_8(a);
    for (int i = 0; i < count; ++i)
        if (b == vfunc_7(a, i))
            return i;
    return -1;
}

namespace fn_f0fa71c6 {

// 0x00235000 fight::ParamValueEntity::vfunc_10 (105 B): equivalent/0x00235000.cpp
// sym: ?v10@ParamValueEntity@fn_f0fa71c6@@UAEPAUEntry_235000@2@HHH@Z @44f4fa09b1f4 @w33af440bc1cb
// STATUS: equivalent (tools/equiv.py level 3: 192 inputs, branch coverage 12/12)
// fight::ParamValueEntity::vfunc_10 @ 0x00235000
Entry_235000* ParamValueEntity::v10(int param, int key0, int key1)
{
    int count = v8(param);
    for (int i = 0; i < count; i++) {
        Entry_235000* entry = v7(param, i);
        if (entry != 0 && entry->key0 == key0 && entry->key1 == key1) {
            if (v6(param, entry))
                return entry;
        }
    }
    return 0;
}

} // namespace fn_f0fa71c6
