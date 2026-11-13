// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0027aec0..0x0027afe0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3f84338 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3f84338 {} using namespace fn_f3f84338;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f3f84338 {
extern "C" char DAT_0042c140[];
class Ref_27aec0 {
  public:
    virtual void f0();
    virtual void f1();
};
class RDLReader {
  public:
    void* vptr;
    Ref_27aec0* member;
    void* data;
    void Close();
};
class A_27af00 {
  public:
    int a;
    int b;
};
struct Pair_27af30 {
    unsigned a;
    unsigned b;
    Pair_27af30& Assign(const Pair_27af30* src);
};
struct Pair_27af70 {
    unsigned a;
    unsigned b;
    Pair_27af70& Assign(const Pair_27af70* src);
};
class Pair_27af90 {
  public:
    int a;
    int b;
    bool operator==(const Pair_27af90& other);
};
extern void* hulk_at_003f6098;


// 0x0027aec0 FUN_0027aec0 (46 B): matches/0x0027aec0.cpp
// sym: ?Close@RDLReader@fn_f3f84338@@QAEXXZ
void RDLReader::Close() {
    vptr = (void*)((hulk_intptr)DAT_0042c140);
    if (member) {
        member->f1();
        member = 0;
        if (data)
            thunk(data);
    }
}


// 0x0027af00 FUN_0027af00 (16 B): matches/0x0027af00.cpp
// sym: @FUN_0027af00@4
// Same code shape as 0x0023f670 (propagated; names are from that function)
extern "C" A_27af00* __fastcall FUN_0027af00(A_27af00* self) {
    self->a = 0;
    self->b = 0;
    return self;
}

} // namespace fn_f3f84338

// 0x0027af10 FUN_0027af10 (18 B): matches/0x0027af10.cpp
// sym: ?FUN_0027af10@Pair_27af10@owners@@QAEPAU12@II@Z
owners::Pair_27af10* owners::Pair_27af10::FUN_0027af10(unsigned int x, unsigned int y) {
    a = x;
    b = y;
    return this;
}

namespace fn_f3f84338 {

// 0x0027af30 FUN_0027af30 (19 B): matches/0x0027af30.cpp
// sym: ?Assign@Pair_27af30@fn_f3f84338@@QAEAAU12@PBU12@@Z
Pair_27af30& Pair_27af30::Assign(const Pair_27af30* src) {
    a = src->a;
    b = src->b;
    return *this;
}


// 0x0027af50 FUN_0027af50 (1 B): matches/0x0027af50.cpp
// sym: _FUN_0027af50
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_0027af50(void* /*this, unused: callers pass it (unb4)*/) {}

} // namespace fn_f3f84338

// 0x0027af60 FUN_0027af60 (16 B): matches/0x0027af60.cpp
// sym: ?FUN_0027af60@Pair_27af60@owners@@QAEXHH@Z
void owners::Pair_27af60::FUN_0027af60(int x, int y) {
    this->a = x;
    this->b = y;
}

namespace fn_f3f84338 {

// 0x0027af70 FUN_0027af70 (19 B): matches/0x0027af70.cpp
// sym: ?Assign@Pair_27af70@fn_f3f84338@@QAEAAU12@PBU12@@Z
// Same code shape as 0x0027af30 (propagated; names are from that function)
Pair_27af70& Pair_27af70::Assign(const Pair_27af70* src) {
    a = src->a;
    b = src->b;
    return *this;
}


// 0x0027af90 FUN_0027af90 (31 B): matches/0x0027af90.cpp
// sym: ??8Pair_27af90@fn_f3f84338@@QAE_NABV01@@Z
bool Pair_27af90::operator==(const Pair_27af90& other) {
    return a == other.a && b == other.b;
}


// 0x0027afb0 FUN_0027afb0 (18 B): matches/0x0027afb0.cpp
// sym: _FUN_0027afb0
// a name's 64-bit hash key
extern "C" unsigned __int64 __cdecl FUN_0027afb0(const char* name) {
    return FUN_002672f0(name, 0, 0);
}


// 0x0027afd0 FUN_0027afd0 (7 B): matches/0x0027afd0.cpp
// sym: @FUN_0027afd0@4
// Same code shape as 0x001b6820 (propagated; names are from that function)
extern "C" void __fastcall FUN_0027afd0(void* self) {
    *(void**)self = &hulk_at_003f6098;
}

} // namespace fn_f3f84338
