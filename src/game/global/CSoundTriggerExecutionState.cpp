// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001eee90..0x001eef00 (kind game, layer game, confidence medium), dominant class CSoundTriggerExecutionState
#include "tree_prelude.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f5500ffb {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5500ffb {} using namespace fn_f5500ffb;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f5500ffb {
class Member_1eee90 {
  public:
    ~Member_1eee90();

  private:
    char data[0x10];
};
class CSoundTriggerExecutionState_1eee90 : public core::IRefCount {
  public:
    virtual void* vfunc_2(unsigned char flags);

  private:
    char pad[0x18];
    Member_1eee90 mMember;
};
extern "C" void* hulk_at_003f6098[];
} // namespace fn_f5500ffb
void __cdecl operator delete[](void*);

namespace fn_f5500ffb {

// 0x001eee90 CSoundTriggerExecutionState::vfunc_2 (111 B): matches/0x001eee90.cpp
// sym: ?vfunc_2@CSoundTriggerExecutionState_1eee90@fn_f5500ffb@@UAEPAXE@Z
void* CSoundTriggerExecutionState_1eee90::vfunc_2(unsigned char flags) {
    CSoundTriggerExecutionState_1eee90* esi = this;
    unsigned char bl = flags;

    if (bl & 2) {
        // Array delete: the element count sits just before the first object.
        int eax = *(int*)((char*)esi - 4);
        void* ebp = (char*)esi - 4;
        int ecx = eax + eax * 4;
        --eax;
        esi = (CSoundTriggerExecutionState_1eee90*)((char*)esi + ecx * 8);
        if (eax >= 0) {
            int edi = eax + 1;
            do {
                esi = (CSoundTriggerExecutionState_1eee90*)((char*)esi - 0x28);
                Member_1eee90* m = (Member_1eee90*)((char*)esi + 0x18);
                m->~Member_1eee90();
                --edi;
                *(void***)esi = hulk_at_003f6098;
            } while (edi);
        }
        if (bl & 1) {
            operator delete[](ebp);
        }
        return ebp;
    }

    Member_1eee90* m = (Member_1eee90*)((char*)esi + 0x18);
    m->~Member_1eee90();
    *(void***)esi = hulk_at_003f6098;
    if (bl & 1) {
        operator delete(esi);
    }
    return esi;
}

} // namespace fn_f5500ffb
