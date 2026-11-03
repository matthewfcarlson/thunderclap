// Same code shape as 0x00066860 (propagated; names are from that function)
#include "gen/owners.h"
struct ThisCall_00230b60 {
};
struct Target_1ad4c0 {
    Target_1ad4c0* Run(int);
};
Target_1ad4c0* Target_1ad4c0::Run(int x) {
    ((owners::X_230b60 *)(((ThisCall_00230b60*)(this))))->FUN_00230b60();
    return this;
}