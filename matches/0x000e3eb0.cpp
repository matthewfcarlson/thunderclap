// Same code shape as 0x000e3c30 (propagated; names are from that function)
#include "gen/global.h"

void TextTable::vfunc_13(int ) {
    int x = *(int*)((char*)this + 0x14c);
    *(int*)((char*)this + 0x148) = x;
    int p = *(int*)((char*)this + 0x150);
    if (p)
        *(int*)((char*)p + 0x44) = x;
}
