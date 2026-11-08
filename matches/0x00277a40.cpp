#include "decls/data/records.h"

// core::Drive's library list (records.h CoreDriveLibraryList), constructed in place by core::Drive's constructor
class Thing_277a40 : public CoreDriveLibraryList {
  public:
    Thing_277a40();
};
extern "C" int* FUN_002705f0();
Thing_277a40::Thing_277a40() {
    cursor = 0;
    buffer = 0;
    size = 0;
    refs = 0;
    heap = 0;
    FUN_002705f0();
    heads[0] = 0;
    tails[0] = 0;
    heads[1] = 0;
    tails[1] = 0;
}
