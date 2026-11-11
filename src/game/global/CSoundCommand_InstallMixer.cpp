// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001ef730..0x001ef7e0 (kind game, layer game, confidence medium), dominant class CSoundCommand_InstallMixer
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f3b01e83 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3b01e83 {} using namespace fn_f3b01e83;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3b01e83 {
struct CSoundCommand_1ef730 {
    virtual void v0() throw();
    virtual void v1() throw();
    int p4, p8, pc;
    CSoundCommand_1ef730() throw() {
        p4 = 0;
        p8 = 0;
        pc = 0;
    }
};
struct CSoundCommand_InstallMixer_1ef730 : CSoundCommand_1ef730 {
    char name[0x20];
    int p30;
    CSoundCommand_InstallMixer_1ef730(const char* s, int v, int unused) throw();
    virtual void v0() throw();
};
class CSoundCommand_1ef770 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public CSoundCommand_1ef770 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);
class Mixer {
  public:
    void Install(void*, int);
};
class Manager {
  public:
    char pad[4];
    Mixer* mixer;
};
class CSoundCommand {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
class CSoundCommand_InstallMixer : public CSoundCommand {
  public:
    char pad[0x10 - 4];
    char data[0x20];
    float value;
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};


// 0x001ef730 FUN_001ef730 (60 B): matches/0x001ef730.cpp
// sym: ??0CSoundCommand_InstallMixer_1ef730@fn_f3b01e83@@QAE@PBDHH@Z
CSoundCommand_InstallMixer_1ef730::CSoundCommand_InstallMixer_1ef730(const char* s, int v, int unused) throw() {
    strcpy(name, s);
    p30 = v;
}


// 0x001ef770 CSoundCommand_InstallMixer::vfunc_0 (31 B): matches/0x001ef770.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f3b01e83@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x001ef790 CSoundCommand_InstallMixer::vfunc_1 (33 B): matches/0x001ef790.cpp
// sym: ?vfunc_1@CSoundCommand_InstallMixer@fn_f3b01e83@@UAEXHH@Z
// data: gManager = DAT_004e370c
void CSoundCommand_InstallMixer::vfunc_1(int, int) {
    (*(Manager**)&DAT_004e370c)->mixer->Install(data, (int)(__int64)value);
}

} // namespace fn_f3b01e83
