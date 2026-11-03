// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_003285d0 @ 0x003285d0
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"

void owners::AccumulatorSource_3285d0::FUN_003285d0(unsigned int unused) {
    if (enabled) {
        ++DAT_00555b84;
        DAT_00555b68 = DAT_00555b68 + x;
        DAT_00555b6c = DAT_00555b6c + y;
        DAT_00555b70 = DAT_00555b70 + z;
        DAT_00555b74 = DAT_00555b74 + w;
        DAT_00555b78 = float(blue) + DAT_00555b78;
        DAT_00555b7c = float(green) + DAT_00555b7c;
        DAT_00555b80 = float(red) + DAT_00555b80;
    }
}
