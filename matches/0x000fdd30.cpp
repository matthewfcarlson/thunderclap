#include "compat/ptr.h"
#include "gen/owners.h"
int __cdecl GetVal(int elem);

class Other_fdd30 {
  public:
    int Check(int v);
};


hulk_intptr owners::Container_fdd30::FUN_000fdd30(hulk_intptr arg) {
    Other_fdd30* o = (Other_fdd30*)((hulk_intptr)arg);
    int e;
    int i = 0;
    if (mCount > 0) {
        int* p = mArray;
        do {
            e = *p;
            if (o->Check(GetVal(e))) {
                return e;
            }
            ++i;
            ++p;
        } while (i < mCount);
    }
    return 0;
}
