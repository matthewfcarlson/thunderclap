// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f94e0..0x001f9530 (kind game, layer game, confidence medium), dominant class CEncounterGenerator::CEncounter
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fd7b8c6e {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fd7b8c6e {} using namespace fn_fd7b8c6e;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fd7b8c6e {
class CEncounterGenerator {
  public:
    class Inner {
      public:
        void Close_0027af50();
        int mValue;
    };
    class CEncounter {
      public:
        virtual ~CEncounter();
        char pad[0x2c];
        Inner mInner;
    };
};


// 0x001f94e0 CEncounterGenerator::CEncounter::vfunc_0 (39 B): matches/0x001f94e0.cpp
// sym: ??_GCEncounter@CEncounterGenerator@fn_fd7b8c6e@@UAEPAXI@Z
CEncounterGenerator::CEncounter::~CEncounter() {
    mInner.Close_0027af50();
}

} // namespace fn_fd7b8c6e
