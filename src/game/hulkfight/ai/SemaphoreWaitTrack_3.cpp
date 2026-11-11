// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00111720..0x001133f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/ai.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fee140f0 {
#define TREE_TU_END }
namespace fn_fee140f0 {} using namespace fn_fee140f0;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fee140f0 {
extern char DAT_004a4558;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_fee140f0
namespace fight {
class TrackFactoryCaster_111720 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class TokenSupressTrack_111720;
} }
namespace fn_fee140f0 {
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int hulk_at_0049850c;
extern char DAT_004a46a8;
int __cdecl FUN_00344e74(const char*, int, const char*, const char*, int);
class TrackFactoryCaster_111800 {
  public:
    virtual bool vfunc_0(const char* s);
    virtual void vfunc_1();
};
} // namespace fn_fee140f0
namespace fight {
class TrackFactoryCaster_111880 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class KeywordWaitTrack_111880 {};
} }
namespace fn_fee140f0 {
extern char DAT_004a4750;
extern "C" int __cdecl Find(void*, int, void*, void*, int);
extern char DAT_004a47f0;
} // namespace fn_fee140f0
namespace fight {
class TrackFactoryCaster_111920 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class ButtonTrack_111920 {};
} }
namespace fn_fee140f0 {
extern char DAT_004a4890;
} // namespace fn_fee140f0
namespace fight {
class TrackFactoryCaster_1119a0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class AIHistorySetTrack_1119a0 {};
} }
namespace fight {
class TrackFactoryCaster_111a40 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class TokenTrack_111a40 {};
} }
namespace fn_fee140f0 {
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(const char*, int, void*, void*, int);
extern char DAT_004a4930;
extern char DAT_004a49d0;
int Helper(hulk_intptr a, int b, void* c, void* d, int e);
class TrackFactoryCaster_111ac0 {
  public:
    virtual void AddRef();
    virtual void Release();
    virtual ~TrackFactoryCaster_111ac0();
};
} // namespace fn_fee140f0
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fee140f0 {
void* FUN_0008d690(unsigned int size);
} // namespace fn_fee140f0
namespace hulkfight { namespace ai {
class AIFightNodeCondition_111c40 {
public:
    void FUN_0010c120();
};
} }
namespace fn_fee140f0 {
class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBranchBase(const char* name) { ((fight::ParamValueBranch *)this)->FUN_00235170(name); }
};
} // namespace fn_fee140f0
namespace fight {
template <class T>
class ParamBranch_111c40 : public ParamBranchBase {
public:
    ParamBranch_111c40(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fee140f0 {
void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_fee140f0
namespace hulkfight { namespace ai {
class DefendingCondition_111ca0 {
public:
    void FUN_0010c130();
};
} }
namespace fn_fee140f0 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_fee140f0
namespace fight {
template <class T>
class ParamBool_111ca0 : public ParamBoolBase {
public:
    ParamBool_111ca0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace ai {
class LeashedCondition_112000 {
public:
    void FUN_0010c1f0();
};
} }
namespace fight {
template <class T>
class ParamBool_112000 : public ParamBoolBase {
public:
    ParamBool_112000(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace ai {
class InActiveCondition_112200 {
public:
    void FUN_0010c250();
    void FUN_0010c270();
};
} }
namespace fight {
template <class T>
class ParamBool_112200 : public ParamBoolBase {
public:
    ParamBool_112200(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_112200 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_112200(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace hulkfight { namespace ai {
class TokenCondition_112570 {
public:
    void FUN_0010c370();
    void FUN_0010c390();
};
} }
namespace fight {
template <class T>
class ParamBool_112570 : public ParamBoolBase {
public:
    ParamBool_112570(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fee140f0 {
class SemaphoreClearTrack {
public:
    void FUN_0010c3b0();
    void FUN_0010c3c0();
    void FUN_0010c3d0();
    void FUN_0010c3f0();
    void FUN_0010c410();
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class TokenSupressTrack {
public:
    void FUN_0010c420();
    void FUN_0010c430();
    void FUN_0010c450();
    void FUN_0010c470();
    void FUN_0010c490();
    void FUN_0010c4b0();
};
} // namespace fn_fee140f0
namespace hulkfight { namespace ai {
class AIHistoryCountTrack_112940 {
public:
    void FUN_0010c4c0();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_112940 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_112940(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fee140f0 {
class ButtonTrack {
public:
    void FUN_0010c560();
    void FUN_0010c570();
    void FUN_0010c590();
    void FUN_0010c5b0();
    void FUN_0010c5d0();
    void FUN_0010c5f0();
};
template <class T>
class ParamEnumConstList : public ParamEnumBase {
public:
    ParamEnumConstList(const char* name, char** t, int n, void (T::*s)()) : ParamEnumBase(name) { table = t; count = n; setter = s; }
    virtual void v0();
    char** table;
    int count;
    void (T::*setter)();
    int unused1c;
};
class SemaphoreWaitTrack {
public:
    void FUN_0010c680();
    void FUN_0010c690();
    void FUN_0010c6a0();
    void FUN_0010c6c0();
    void FUN_0010c6e0();
    void FUN_0010c700();
};
class Params_113080 {
  public:
    int x;
};
extern Params_113080 hulk_at_00494b44;
extern Params_113080 hulk_at_00494b60;
int __cdecl Check(void*, int, Params_113080*, Params_113080*, int);
class Object_113080 {
  public:
    int Init_0010ec00(hulkfight::ai::ButtonTrack*, hulk_intptr);
};
Object_113080* __cdecl Alloc_0008d690(int);
struct RefCounted_1130d0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040dd34[];
class ButtonAction_1130d0 {
  public:
    ButtonAction_1130d0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1130d0* m_20;
};
struct RefCounted_113170 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040dd50[];
class HulkAction_113170 {
  public:
    HulkAction_113170* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_113170* m_20;
};
struct RefCounted_113210 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040dd6c[];
class TokenSupressAction_113210 {
  public:
    TokenSupressAction_113210* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_113210* m_20;
};
struct RefCounted_1132b0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040dd88[];
class TokenAction_1132b0 {
  public:
    TokenAction_1132b0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1132b0* m_20;
};
struct RefCounted_113350 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040dda4[];
class AIHistorySetAction_113350 {
  public:
    AIHistorySetAction_113350* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_113350* m_20;
};

} // namespace fn_fee140f0

// 0x00111720 fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenSupressTrack>::vfunc_0 (36 B): matches/0x00111720.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VTokenSupressTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenSupressTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a4558, 0) != 0;
}


// 0x00111750 fight::ParamFloatConstRange<hulkfight::ai::TokenSupressTrack>::vfunc_0 (30 B): matches/0x00111750.cpp
// sym: ??_G?$ParamFloatConstRange@VTokenSupressTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::TokenSupressTrack>::~ParamFloatConstRange() {}


// 0x00111770 fight::ParamBool<hulkfight::ai::TokenSupressTrack>::vfunc_0 (30 B): matches/0x00111770.cpp
// sym: ??_G?$ParamBool@VTokenSupressTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::TokenSupressTrack>::~ParamBool() {}


// 0x001117a0 fight::TrackFactoryCasterTemplate<hulkfight::ai::AIHistoryCountTrack>::vfunc_0 (36 B): matches/0x001117a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VAIHistoryCountTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::AIHistoryCountTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_0049850c, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x001117d0 fight::ParamFloatConstRange<hulkfight::ai::AIHistoryCountTrack>::vfunc_0 (30 B): matches/0x001117d0.cpp
// sym: ??_G?$ParamFloatConstRange@VAIHistoryCountTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::AIHistoryCountTrack>::~ParamFloatConstRange() {}


// 0x00111800 fight::TrackFactoryCasterTemplate<hulkfight::ai::HulkActionTrack>::vfunc_0 (36 B): matches/0x00111800.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHulkActionTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::HulkActionTrack>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    int r = FUN_00344e74(s, 0, (const char*)&DAT_0049850c, (const char*)&DAT_004a46a8, 0);
    return r != 0;
}


// 0x00111830 fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>::vfunc_0 (30 B): matches/0x00111830.cpp
// sym: ??_G?$ParamFloatConstRange@VHulkActionTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>::~ParamFloatConstRange() {}


// 0x00111850 fight::ParamName<hulkfight::ai::HulkActionTrack>::vfunc_0 (30 B): matches/0x00111850.cpp
// sym: ??_G?$ParamName@VHulkActionTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::ai::HulkActionTrack>::~ParamName() {}


// 0x00111880 fight::TrackFactoryCasterTemplate<hulkfight::ai::KeywordWaitTrack>::vfunc_0 (36 B): matches/0x00111880.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VKeywordWaitTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::KeywordWaitTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a4750, 0) != 0;
}


// 0x001118b0 fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>::vfunc_0 (30 B): matches/0x001118b0.cpp
// sym: ??_G?$ParamFloatConstRange@VKeywordWaitTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>::~ParamFloatConstRange() {}


// 0x001118d0 fight::ParamName<hulkfight::ai::KeywordWaitTrack>::vfunc_0 (30 B): matches/0x001118d0.cpp
// sym: ??_G?$ParamName@VKeywordWaitTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::ai::KeywordWaitTrack>::~ParamName() {}


// 0x001118f0 fight::ParamBool<hulkfight::ai::KeywordWaitTrack>::vfunc_0 (30 B): matches/0x001118f0.cpp
// sym: ??_G?$ParamBool@VKeywordWaitTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::KeywordWaitTrack>::~ParamBool() {}


// 0x00111920 fight::TrackFactoryCasterTemplate<hulkfight::ai::ButtonTrack>::vfunc_0 (36 B): matches/0x00111920.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VButtonTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::ButtonTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Find(p, 0, &DAT_0049850c, &DAT_004a47f0, 0) != 0;
}


// 0x00111950 fight::ParamFloatConstRange<hulkfight::ai::ButtonTrack>::vfunc_0 (30 B): matches/0x00111950.cpp
// sym: ??_G?$ParamFloatConstRange@VButtonTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::ButtonTrack>::~ParamFloatConstRange() {}


// 0x00111970 fight::ParamEnumConstList<hulkfight::ai::ButtonTrack>::vfunc_0 (30 B): matches/0x00111970.cpp
// sym: ??_G?$ParamEnumConstList@VButtonTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::ButtonTrack>::~ParamEnumConstList() {}


// 0x001119a0 fight::TrackFactoryCasterTemplate<hulkfight::ai::AIHistorySetTrack>::vfunc_0 (36 B): matches/0x001119a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VAIHistorySetTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::AIHistorySetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a4890, 0) != 0;
}


// 0x001119d0 fight::ParamFloatConstRange<hulkfight::ai::AIHistorySetTrack>::vfunc_0 (30 B): matches/0x001119d0.cpp
// sym: ??_G?$ParamFloatConstRange@VAIHistorySetTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::AIHistorySetTrack>::~ParamFloatConstRange() {}


// 0x001119f0 fight::ParamBool<hulkfight::ai::AIHistorySetTrack>::vfunc_0 (30 B): matches/0x001119f0.cpp
// sym: ??_G?$ParamBool@VAIHistorySetTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::AIHistorySetTrack>::~ParamBool() {}


// 0x00111a10 fight::ParamName<hulkfight::ai::AIHistorySetTrack>::vfunc_0 (30 B): matches/0x00111a10.cpp
// sym: ??_G?$ParamName@VAIHistorySetTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::ai::AIHistorySetTrack>::~ParamName() {}


// 0x00111a40 fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenTrack>::vfunc_0 (36 B): matches/0x00111a40.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VTokenTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenTrack>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &DAT_0049850c, &DAT_004a4930, 0) != 0;
}


// 0x00111a70 fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>::vfunc_0 (30 B): matches/0x00111a70.cpp
// sym: ??_G?$ParamFloatConstRange@VTokenTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>::~ParamFloatConstRange() {}


// 0x00111a90 fight::ParamBool<hulkfight::ai::TokenTrack>::vfunc_0 (30 B): matches/0x00111a90.cpp
// sym: ??_G?$ParamBool@VTokenTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::TokenTrack>::~ParamBool() {}


// 0x00111ab0 FUN_00111ab0 (9 B): matches/0x00111ab0.cpp [wrapped: conflict: fight::TrackFactoryCasterTemplate]
// sym: ??0?$TrackFactoryCasterTemplate@VSemaphoreWaitTrack@ai@hulkfight@fn_00111ab0@@@fight@fn_00111ab0@@QAE@XZ
namespace fn_00111ab0 {
namespace hulkfight {
namespace ai {
class SemaphoreWaitTrack;
}
} // namespace hulkfight
namespace fight {
template <class T> class TrackFactoryCasterTemplate {
  public:
    TrackFactoryCasterTemplate();
    virtual void f();
};
template <> TrackFactoryCasterTemplate<hulkfight::ai::SemaphoreWaitTrack>::TrackFactoryCasterTemplate() {}
} // namespace fight
} // namespace fn_00111ab0


// 0x00111ac0 fight::TrackFactoryCasterTemplate<hulkfight::ai::SemaphoreWaitTrack>::vfunc_0 (36 B): matches/0x00111ac0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VSemaphoreWaitTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::SemaphoreWaitTrack>::vfunc_0(void* __p0) { hulk_intptr arg = (hulk_intptr)__p0;

    int x = Helper(arg, 0, (void*)&DAT_0049850c, (void*)&DAT_004a49d0, 0);
    return (x != 0) ? 1 : 0;
}


// 0x00111af0 fight::ParamFloatConstRange<hulkfight::ai::SemaphoreWaitTrack>::vfunc_0 (30 B): matches/0x00111af0.cpp
// sym: ??_G?$ParamFloatConstRange@VSemaphoreWaitTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::SemaphoreWaitTrack>::~ParamFloatConstRange() {}


// 0x00111b10 fight::ParamName<hulkfight::ai::SemaphoreWaitTrack>::vfunc_0 (30 B): matches/0x00111b10.cpp
// sym: ??_G?$ParamName@VSemaphoreWaitTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::ai::SemaphoreWaitTrack>::~ParamName() {}


// 0x00111b30 fight::ParamBool<hulkfight::ai::SemaphoreWaitTrack>::vfunc_0 (30 B): matches/0x00111b30.cpp
// sym: ??_G?$ParamBool@VSemaphoreWaitTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::SemaphoreWaitTrack>::~ParamBool() {}

namespace fn_fee140f0 {

// 0x00111c40 FUN_00111c40 (95 B): equivalent/0x00111c40.cpp
// sym: _FUN_00111c40 @8c95712c4ae4 @wb565d92c2ae9
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_00111c40 @ 0x00111c40
extern "C" void FUN_00111c40()
{
    if (DAT_004e0aec == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_111c40<hulkfight::ai::AIFightNodeCondition_111c40>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBranch_111c40<hulkfight::ai::AIFightNodeCondition_111c40>("branch", &hulkfight::ai::AIFightNodeCondition_111c40::FUN_0010c120);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ae8), params, 1);
    }
    DAT_004e0aec++;
}


// 0x00111ca0 FUN_00111ca0 (95 B): equivalent/0x00111ca0.cpp
// sym: _FUN_00111ca0 @f120cb5eb71f @w1886b39e903e
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_00111ca0 @ 0x00111ca0
extern "C" void FUN_00111ca0()
{
    if (DAT_004e0af4 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_111ca0<hulkfight::ai::DefendingCondition_111ca0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_111ca0<hulkfight::ai::DefendingCondition_111ca0>("defending", &hulkfight::ai::DefendingCondition_111ca0::FUN_0010c130);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0af0), params, 1);
    }
    DAT_004e0af4++;
}

} // namespace fn_fee140f0

// 0x00111df0 FUN_00111df0 (176 B): equivalent/0x00111df0.cpp [wrapped: conflict: fight::ParamEnumConstList; fight::ParamString; hulkfight::ai::HulkActionLargestCondition]
// sym: _FUN_00111df0 @62f7d15f9646 @w6cb88f2ce1c5
namespace fn_00111df0 {
// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 6/6)
// FUN_00111df0 @ 0x00111df0


void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class HulkActionLargestCondition {
public:
    void FUN_0010c180();
    void FUN_0010c9b0();
};
}
}

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamString : public ParamStringBase {
public:
    ParamString(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00111df0()
{
    if (DAT_004e0b04 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::HulkActionLargestCondition::FUN_0010c180);
        mem = FUN_0008d690((int)sizeof(fight::ParamString<hulkfight::ai::HulkActionLargestCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamString<hulkfight::ai::HulkActionLargestCondition>("text", &hulkfight::ai::HulkActionLargestCondition::FUN_0010c9b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b00), params, 2);
    }
    DAT_004e0b04++;
}
} // namespace fn_00111df0


// 0x00111ea0 FUN_00111ea0 (176 B): equivalent/0x00111ea0.cpp [wrapped: conflict: fight::ParamEnumConstList; fight::ParamIntConstRange; hulkfight::ai::PropsToChuckCondition]
// sym: _FUN_00111ea0 @68b83cd08490 @wd773e97c09a4
namespace fn_00111ea0 {
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// FUN_00111ea0 @ 0x00111ea0


void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class PropsToChuckCondition {
public:
    void FUN_0010c1a0();
    void FUN_0010c1c0();
};
}
}

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00111ea0()
{
    if (DAT_004e0b0c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::PropsToChuckCondition::FUN_0010c1a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange<hulkfight::ai::PropsToChuckCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamIntConstRange<hulkfight::ai::PropsToChuckCondition>("number", &hulkfight::ai::PropsToChuckCondition::FUN_0010c1c0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b08), params, 2);
    }
    DAT_004e0b0c++;
}
} // namespace fn_00111ea0


// 0x00111f50 FUN_00111f50 (176 B): equivalent/0x00111f50.cpp [wrapped: conflict: fight::ParamEnumConstList; fight::ParamString; hulkfight::ai::HulkActionRecentCondition]
// sym: _FUN_00111f50 @dd64dcef0456 @wf69c5551d0a0
namespace fn_00111f50 {
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00111f50 @ 0x00111f50


void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class HulkActionRecentCondition {
public:
    void FUN_0010c1d0();
    void FUN_0010cb00();
};
}
}

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamString : public ParamStringBase {
public:
    ParamString(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00111f50()
{
    if (DAT_004e0b14 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::HulkActionRecentCondition::FUN_0010c1d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamString<hulkfight::ai::HulkActionRecentCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamString<hulkfight::ai::HulkActionRecentCondition>("text", &hulkfight::ai::HulkActionRecentCondition::FUN_0010cb00);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b10), params, 2);
    }
    DAT_004e0b14++;
}
} // namespace fn_00111f50

namespace fn_fee140f0 {

// 0x00112000 FUN_00112000 (95 B): equivalent/0x00112000.cpp
// sym: _FUN_00112000 @d009095dfc64 @wbce8b64b3b78
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// FUN_00112000 @ 0x00112000
extern "C" void FUN_00112000()
{
    if (DAT_004e0b1c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_112000<hulkfight::ai::LeashedCondition_112000>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_112000<hulkfight::ai::LeashedCondition_112000>("leashed", &hulkfight::ai::LeashedCondition_112000::FUN_0010c1f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b18), params, 1);
    }
    DAT_004e0b1c++;
}

} // namespace fn_fee140f0

// 0x00112150 FUN_00112150 (176 B): equivalent/0x00112150.cpp [wrapped: conflict: fight::ParamEnumConstList; fight::ParamString; hulkfight::ai::FormationReadyCondition]
// sym: _FUN_00112150 @90d4e72c189e @w119e8a350c68
namespace fn_00112150 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_00112150 @ 0x00112150


void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class FormationReadyCondition {
public:
    void FUN_0010c240();
    void FUN_0010cd20();
};
}
}

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamString : public ParamStringBase {
public:
    ParamString(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00112150()
{
    if (DAT_004e0b2c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::FormationReadyCondition::FUN_0010c240);
        mem = FUN_0008d690((int)sizeof(fight::ParamString<hulkfight::ai::FormationReadyCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamString<hulkfight::ai::FormationReadyCondition>("text", &hulkfight::ai::FormationReadyCondition::FUN_0010cd20);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b28), params, 2);
    }
    DAT_004e0b2c++;
}
} // namespace fn_00112150

namespace fn_fee140f0 {

// 0x00112200 FUN_00112200 (176 B): equivalent/0x00112200.cpp
// sym: _FUN_00112200 @fd964f6dc84c @wdc63c4b0ad08
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// FUN_00112200 @ 0x00112200
extern "C" void FUN_00112200()
{
    if (DAT_004e0b34 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_112200<hulkfight::ai::InActiveCondition_112200>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_112200<hulkfight::ai::InActiveCondition_112200>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::InActiveCondition_112200::FUN_0010c250);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_112200<hulkfight::ai::InActiveCondition_112200>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_112200<hulkfight::ai::InActiveCondition_112200>("active", &hulkfight::ai::InActiveCondition_112200::FUN_0010c270);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b30), params, 2);
    }
    DAT_004e0b34++;
}

} // namespace fn_fee140f0

// 0x001124c0 FUN_001124c0 (176 B): equivalent/0x001124c0.cpp [wrapped: conflict: fight::ParamEnumConstList; fight::ParamIntConstRange; hulkfight::ai::RandomKeyWordWaitCondition]
// sym: _FUN_001124c0 @6274aa4302b7 @w9fd538eb68de
namespace fn_001124c0 {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_001124c0 @ 0x001124c0


void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class RandomKeyWordWaitCondition {
public:
    void FUN_0010c330();
    void FUN_0010c350();
};
}
}

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_001124c0()
{
    if (DAT_004e0b4c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::RandomKeyWordWaitCondition::FUN_0010c330);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange<hulkfight::ai::RandomKeyWordWaitCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamIntConstRange<hulkfight::ai::RandomKeyWordWaitCondition>("value", &hulkfight::ai::RandomKeyWordWaitCondition::FUN_0010c350);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b48), params, 2);
    }
    DAT_004e0b4c++;
}
} // namespace fn_001124c0

namespace fn_fee140f0 {

// 0x00112570 FUN_00112570 (158 B): equivalent/0x00112570.cpp
// sym: _FUN_00112570 @31d6dcd00a94 @wabe9b88601ec
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00112570 @ 0x00112570
extern "C" void FUN_00112570()
{
    if (DAT_004e0b54 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_112570<hulkfight::ai::TokenCondition_112570>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_112570<hulkfight::ai::TokenCondition_112570>("oRNoOneHas", &hulkfight::ai::TokenCondition_112570::FUN_0010c370);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_112570<hulkfight::ai::TokenCondition_112570>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_112570<hulkfight::ai::TokenCondition_112570>("have", &hulkfight::ai::TokenCondition_112570::FUN_0010c390);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b50), params, 2);
    }
    DAT_004e0b54++;
}

} // namespace fn_fee140f0

// 0x00112610 FUN_00112610 (113 B): equivalent/0x00112610.cpp [wrapped: conflict: fight::ParamEnumConstList; hulkfight::ai::FightingOtherNPCCondition]
// sym: _FUN_00112610 @a8cbe724eda9 @w31859f5436b5
namespace fn_00112610 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00112610 @ 0x00112610


void* FUN_0008d690(unsigned int size);

namespace hulkfight { namespace ai {
class FightingOtherNPCCondition {
public:
    void FUN_0010c3a0();
};
} }

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00112610()
{
    if (DAT_004e0b5c == 0) {
        void* params[1];
        void* mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::FightingOtherNPCCondition::FUN_0010c3a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b58), params, 1);
    }
    DAT_004e0b5c++;
}
} // namespace fn_00112610

namespace fn_fee140f0 {

// 0x00112690 FUN_00112690 (307 B): equivalent/0x00112690.cpp
// sym: _FUN_00112690 @c7f6f25683df @w15154a6d6fb5
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 12/12)
// FUN_00112690 @ 0x00112690
extern "C" void FUN_00112690()
{
    if (DAT_004e0b64 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SemaphoreClearTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<SemaphoreClearTrack>("timeBegin", &SemaphoreClearTrack::FUN_0010c3b0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SemaphoreClearTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<SemaphoreClearTrack>("timeEnd", &SemaphoreClearTrack::FUN_0010c3c0);
        mem = FUN_0008d690((int)sizeof(ParamName<SemaphoreClearTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamName<SemaphoreClearTrack>("semaphore", &SemaphoreClearTrack::FUN_0010c3d0);
        mem = FUN_0008d690((int)sizeof(ParamBool<SemaphoreClearTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBool<SemaphoreClearTrack>("clearEveryFrame", &SemaphoreClearTrack::FUN_0010c3f0);
        mem = FUN_0008d690((int)sizeof(ParamBool<SemaphoreClearTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<SemaphoreClearTrack>("clearAll", &SemaphoreClearTrack::FUN_0010c410);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b60), params, 5);
    }
    DAT_004e0b64++;
}


// 0x001127d0 FUN_001127d0 (358 B): equivalent/0x001127d0.cpp
// sym: _FUN_001127d0 @5604d43867db @wb0bee0121ca3
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 14/14)
// FUN_001127d0 @ 0x001127d0
extern "C" void FUN_001127d0()
{
    if (DAT_004e0b6c == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<TokenSupressTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<TokenSupressTrack>("timeBegin", &TokenSupressTrack::FUN_0010c420);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<TokenSupressTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<TokenSupressTrack>("timeEnd", &TokenSupressTrack::FUN_0010c430);
        mem = FUN_0008d690((int)sizeof(ParamBool<TokenSupressTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<TokenSupressTrack>("supressEveryFrame", &TokenSupressTrack::FUN_0010c450);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<TokenSupressTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<TokenSupressTrack>("floatDelayDuration", &TokenSupressTrack::FUN_0010c470);
        mem = FUN_0008d690((int)sizeof(ParamBool<TokenSupressTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<TokenSupressTrack>("floatDelayDurationPermenant", &TokenSupressTrack::FUN_0010c490);
        mem = FUN_0008d690((int)sizeof(ParamBool<TokenSupressTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<TokenSupressTrack>("floatDelayEndOnTrackFinish", &TokenSupressTrack::FUN_0010c4b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b68), params, 6);
    }
    DAT_004e0b6c++;
}


// 0x00112940 FUN_00112940 (95 B): equivalent/0x00112940.cpp
// sym: _FUN_00112940 @3fc710bba90d @w68eb935fc21c
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 4/4)
// FUN_00112940 @ 0x00112940
extern "C" void FUN_00112940()
{
    if (DAT_004e0b74 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_112940<hulkfight::ai::AIHistoryCountTrack_112940>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_112940<hulkfight::ai::AIHistoryCountTrack_112940>("value", &hulkfight::ai::AIHistoryCountTrack_112940::FUN_0010c4c0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b70), params, 1);
    }
    DAT_004e0b74++;
}


// 0x00112ba0 FUN_00112ba0 (386 B): equivalent/0x00112ba0.cpp
// sym: _FUN_00112ba0 @bb11189dd8c0 @wa95c0d1900c4
// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 14/14)
// FUN_00112ba0 @ 0x00112ba0
extern "C" void FUN_00112ba0()
{
    if (DAT_004e0b8c == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ButtonTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<ButtonTrack>("timeBegin", &ButtonTrack::FUN_0010c560);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ButtonTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<ButtonTrack>("timeEnd", &ButtonTrack::FUN_0010c570);
        mem = FUN_0008d690((int)sizeof(ParamEnumConstList<ButtonTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamEnumConstList<ButtonTrack>("button", ((char**)&DAT_0049ee30), 13, &ButtonTrack::FUN_0010c590);
        mem = FUN_0008d690((int)sizeof(ParamEnumConstList<ButtonTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamEnumConstList<ButtonTrack>("state", ((char**)&DAT_0049ee64), 4, &ButtonTrack::FUN_0010c5b0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ButtonTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<ButtonTrack>("time", &ButtonTrack::FUN_0010c5d0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ButtonTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<ButtonTrack>("value", &ButtonTrack::FUN_0010c5f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b88), params, 6);
    }
    DAT_004e0b8c++;
}


// 0x00112f10 FUN_00112f10 (358 B): equivalent/0x00112f10.cpp
// sym: _FUN_00112f10 @991cdd790143 @w457cc000a251
// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 14/14)
// FUN_00112f10 @ 0x00112f10
extern "C" void FUN_00112f10()
{
    if (DAT_004e0ba4 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SemaphoreWaitTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<SemaphoreWaitTrack>("timeBegin", &SemaphoreWaitTrack::FUN_0010c680);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SemaphoreWaitTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<SemaphoreWaitTrack>("timeEnd", &SemaphoreWaitTrack::FUN_0010c690);
        mem = FUN_0008d690((int)sizeof(ParamName<SemaphoreWaitTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamName<SemaphoreWaitTrack>("semaphore", &SemaphoreWaitTrack::FUN_0010c6a0);
        mem = FUN_0008d690((int)sizeof(ParamBool<SemaphoreWaitTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBool<SemaphoreWaitTrack>("interuptable", &SemaphoreWaitTrack::FUN_0010c6c0);
        mem = FUN_0008d690((int)sizeof(ParamBool<SemaphoreWaitTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<SemaphoreWaitTrack>("useCharacterTimeout", &SemaphoreWaitTrack::FUN_0010c6e0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SemaphoreWaitTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<SemaphoreWaitTrack>("timeoutOverride", &SemaphoreWaitTrack::FUN_0010c700);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ba0), params, 6);
    }
    DAT_004e0ba4++;
}

} // namespace fn_fee140f0

// 0x00113080 hulkfight::ai::ButtonTrack::vfunc_10 (70 B): matches/0x00113080.cpp
// sym: ?vfunc_10@ButtonTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::ai::ButtonTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0);
    if (result) {
        Object_113080* p = Alloc_0008d690(0x24);
        if (p)
            return p->Init_0010ec00(this, c);
    }
    return 0;
}

namespace fn_fee140f0 {

// 0x001130d0 hulkfight::ai::ButtonAction::vfunc_2 (71 B): matches/0x001130d0.cpp
// sym: ?vfunc_2@ButtonAction_1130d0@fn_fee140f0@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
ButtonAction_1130d0* ButtonAction_1130d0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040dd34;
    RefCounted_1130d0* q = *(RefCounted_1130d0* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}


// 0x00113170 hulkfight::ai::HulkAction::vfunc_2 (71 B): matches/0x00113170.cpp
// sym: ?vfunc_2@HulkAction_113170@fn_fee140f0@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
HulkAction_113170* HulkAction_113170::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040dd50;
    RefCounted_113170* q = *(RefCounted_113170* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}


// 0x00113210 hulkfight::ai::TokenSupressAction::vfunc_2 (71 B): matches/0x00113210.cpp
// sym: ?vfunc_2@TokenSupressAction_113210@fn_fee140f0@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
TokenSupressAction_113210* TokenSupressAction_113210::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040dd6c;
    RefCounted_113210* q = *(RefCounted_113210* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}


// 0x001132b0 hulkfight::ai::TokenAction::vfunc_2 (71 B): matches/0x001132b0.cpp
// sym: ?vfunc_2@TokenAction_1132b0@fn_fee140f0@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
TokenAction_1132b0* TokenAction_1132b0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040dd88;
    RefCounted_1132b0* q = *(RefCounted_1132b0* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}


// 0x00113350 hulkfight::ai::AIHistorySetAction::vfunc_2 (71 B): matches/0x00113350.cpp
// sym: ?vfunc_2@AIHistorySetAction_113350@fn_fee140f0@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
AIHistorySetAction_113350* AIHistorySetAction_113350::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040dda4;
    RefCounted_113350* q = *(RefCounted_113350* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}

} // namespace fn_fee140f0
