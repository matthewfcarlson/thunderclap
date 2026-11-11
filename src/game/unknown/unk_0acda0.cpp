// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000acda0..0x000ad990 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6229ecf {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6229ecf {} using namespace fn_f6229ecf;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f6229ecf {
class Obj_acda0 {
    char pad[0x494];
    float value;

  public:
    float GetValue();
};
struct Item_acf50 {
    void Apply_000b07b0(int);
};
struct Owner_acf50 {
    char pad[0x10];
    int count;
    Item_acf50** items;
    void Apply(int);
};
struct Item_ad060 {
    void Apply_000b07c0(int);
};
struct Owner_ad060 {
    char pad[0x10];
    int count;
    Item_ad060** items;
    void Apply(int);
};
struct Item_ad170 {
    void Apply_000b07d0(int);
};
struct Owner_ad170 {
    char pad[0x10];
    int count;
    Item_ad170** items;
    void Apply(int);
};
struct Item_ad280 {
    void Apply_000b07e0(int);
};
struct Owner_ad280 {
    char pad[0x10];
    int count;
    Item_ad280** items;
    void Apply(int);
};
struct Item_ad2b0 {
    char pad[0x4a0];
    float value;
};
struct Container_ad2b0 {
    char pad[0x10];
    int count;
    Item_ad2b0** items;
    hulk_freg target();
};
struct Item_ad390 {
    void Apply_000b07f0(int);
};
struct Owner_ad390 {
    char pad[0x10];
    int count;
    Item_ad390** items;
    void Apply(int);
};
struct Item_ad3c0 {
    char padding[0x4a4];
    float value;
};
struct Collection_ad3c0 {
    char padding[0x10];
    int count;
    Item_ad3c0** items;
    hulk_freg FUN_000ad3c0();
};
struct Item_ad4a0 {
    void Apply_000b0800(int);
};
struct Owner_ad4a0 {
    char pad[0x10];
    int count;
    Item_ad4a0** items;
    void Apply(int);
};
struct Item_ad580 {
    char pad[0x54];
    int id;
    int Do_000b0810(int a, int b);
};
int Fallback_000b08a0(int a, int b);
class Manager_ad580 {
    char pad[0x10];
    int count;
    Item_ad580** items;

  public:
    hulk_intptr Run(int id, int a, int b);
};
class Item_ad7b0 {
    char pad[0x54];

  public:
    int key;
    int action_000b0930(int a, int b);
};
int fallback_000b09c0(int a, int b);
class Owner_ad7b0 {
    char pad[0x10];
    int count;
    Item_ad7b0** items;

  public:
    hulk_intptr run(int key, int a, int b);
};
class Item {
    char pad[0x54];

  public:
    int key;
    bool Invoke_000b19e0(int a, int b, int c);
};
class Obj {
    char pad[0x10];

  public:
    int count;
    Item** items;
    bool Find(int key, int a, int b, int c);
};
class Item_ad930 {
  public:
    void Release_000b1db0();
};
class Owner_ad930 {
  public:
    char pad0[0x10];
    int count;
    Item_ad930** items;
    void Clear();
};
class Item_ad960 {
  public:
    void Release_000b1aa0();
};
class Owner_ad960 {
  public:
    char pad0[0x10];
    int count;
    Item_ad960** items;
    void Clear();
};


// 0x000acda0 FUN_000acda0 (7 B): matches/0x000acda0.cpp
// sym: ?GetValue@Obj_acda0@fn_f6229ecf@@QAEMXZ
float Obj_acda0::GetValue() {
    return value;
}

} // namespace fn_f6229ecf

// 0x000ace20 FUN_000ace20 (13 B): matches/0x000ace20.cpp
// sym: ?FUN_000ace20@C_ace20@owners@@QAEHH@Z
hulk_intptr owners::C_ace20::FUN_000ace20(int i) {
    return items[i];
}

namespace fn_f6229ecf {

// 0x000acf50 FUN_000acf50 (44 B): matches/0x000acf50.cpp
// sym: ?Apply@Owner_acf50@fn_f6229ecf@@QAEXH@Z
void Owner_acf50::Apply(int value) {
    int i = 0;
    if (count > 0)
        do {
            items[i]->Apply_000b07b0(value);
            ++i;
        } while (i < count);
}


// 0x000ad060 FUN_000ad060 (44 B): matches/0x000ad060.cpp
// sym: ?Apply@Owner_ad060@fn_f6229ecf@@QAEXH@Z
// Same code shape as 0x000acf50 (propagated; names are from that function)
void Owner_ad060::Apply(int value) {
    int i = 0;
    if (count > 0)
        do {
            items[i]->Apply_000b07c0(value);
            ++i;
        } while (i < count);
}


// 0x000ad170 FUN_000ad170 (44 B): matches/0x000ad170.cpp
// sym: ?Apply@Owner_ad170@fn_f6229ecf@@QAEXH@Z
// Same code shape as 0x000acf50 (propagated; names are from that function)
void Owner_ad170::Apply(int value) {
    int i = 0;
    if (count > 0)
        do {
            items[i]->Apply_000b07d0(value);
            ++i;
        } while (i < count);
}


// 0x000ad280 FUN_000ad280 (44 B): matches/0x000ad280.cpp
// sym: ?Apply@Owner_ad280@fn_f6229ecf@@QAEXH@Z
// Same code shape as 0x000acf50 (propagated; names are from that function)
void Owner_ad280::Apply(int value) {
    int i = 0;
    if (count > 0)
        do {
            items[i]->Apply_000b07e0(value);
            ++i;
        } while (i < count);
}


// 0x000ad2b0 FUN_000ad2b0 (215 B): matches/0x000ad2b0.cpp
// sym: ?target@Container_ad2b0@fn_f6229ecf@@QAEMXZ
hulk_freg Container_ad2b0::target() {
    float result = 3.402823466e+38f;
    for (int i = 0; i < count; ++i) {
        float value = items[i]->value;
        if (value < result)
            result = value;
    }
    return result;
}


// 0x000ad390 FUN_000ad390 (44 B): matches/0x000ad390.cpp
// sym: ?Apply@Owner_ad390@fn_f6229ecf@@QAEXH@Z
// Same code shape as 0x000acf50 (propagated; names are from that function)
void Owner_ad390::Apply(int value) {
    int i = 0;
    if (count > 0)
        do {
            items[i]->Apply_000b07f0(value);
            ++i;
        } while (i < count);
}


// 0x000ad3c0 FUN_000ad3c0 (215 B): matches/0x000ad3c0.cpp
// sym: ?FUN_000ad3c0@Collection_ad3c0@fn_f6229ecf@@QAEMXZ
hulk_freg Collection_ad3c0::FUN_000ad3c0() {
    float maximum = 1.1754943508222875e-38f;
    for (int i = 0; i < count; ++i) {
        float value = items[i]->value;
        if (value > maximum)
            maximum = value;
    }
    return maximum;
}


// 0x000ad4a0 FUN_000ad4a0 (44 B): matches/0x000ad4a0.cpp
// sym: ?Apply@Owner_ad4a0@fn_f6229ecf@@QAEXH@Z
// Same code shape as 0x000acf50 (propagated; names are from that function)
void Owner_ad4a0::Apply(int value) {
    int i = 0;
    if (count > 0)
        do {
            items[i]->Apply_000b0800(value);
            ++i;
        } while (i < count);
}


// 0x000ad580 FUN_000ad580 (88 B): matches/0x000ad580.cpp
// sym: ?Run@Manager_ad580@fn_f6229ecf@@QAEHHHH@Z
hulk_intptr Manager_ad580::Run(int id, int a, int b) {
    int n = count;
    int i = 0;
    if (n > 0) {
        Item_ad580** arr = items;
        int key = id;
        Item_ad580** cur = arr;
        do {
            Item_ad580* p = *cur;
            if (p && p->id == key) {
                return arr[i]->Do_000b0810(a, b);
            }
            ++i;
            ++cur;
        } while (i < n);
    }
    return Fallback_000b08a0(a, b);
}


// 0x000ad7b0 FUN_000ad7b0 (88 B): matches/0x000ad7b0.cpp
// sym: ?run@Owner_ad7b0@fn_f6229ecf@@QAEHHHH@Z
hulk_intptr Owner_ad7b0::run(int key, int a, int b) {
    for (int i = 0; i < count; i++) {
        if (items[i] && items[i]->key == key) {
            return items[i]->action_000b0930(a, b);
        }
    }
    return fallback_000b09c0(a, b);
}


// 0x000ad810 FUN_000ad810 (77 B): matches/0x000ad810.cpp
// sym: ?Find@Obj@fn_f6229ecf@@QAE_NHHHH@Z
bool Obj::Find(int key, int a, int b, int c) {
    int n = count;
    int i = 0;
    if (i < n) {
        Item** cur = items;
        do {
            Item* p = *cur;
            if (p && p->key == key)
                return items[i]->Invoke_000b19e0(a, b, c);
            ++i;
            ++cur;
        } while (i < n);
    }
    return false;
}


// 0x000ad930 FUN_000ad930 (42 B): matches/0x000ad930.cpp
// sym: ?Clear@Owner_ad930@fn_f6229ecf@@QAEXXZ
void Owner_ad930::Clear() {
    for (int i = 0; i < count; ++i) {
        Item_ad930* p = items[i];
        if (p)
            p->Release_000b1db0();
    }
}


// 0x000ad960 FUN_000ad960 (42 B): matches/0x000ad960.cpp
// sym: ?Clear@Owner_ad960@fn_f6229ecf@@QAEXXZ
// Same code shape as 0x000ad930 (propagated; names are from that function)
void Owner_ad960::Clear() {
    for (int i = 0; i < count; ++i) {
        Item_ad960* p = items[i];
        if (p)
            p->Release_000b1aa0();
    }
}

} // namespace fn_f6229ecf
