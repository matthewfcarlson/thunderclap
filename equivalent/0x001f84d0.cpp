// STATUS: equivalent (tools/equiv.py level 3: 3042 inputs, branch coverage 15/18, incomplete)
// FUN_001f84d0 @ 0x001f84d0
#include "gen/owners.h"
bool owners::Key_1f84d0::FUN_001f84d0(const owners::Key_1f84d0 *other) {
    if (category < other->category) return true;
    if (category > other->category) return false;
    if (high < other->high) return true;
    if (high > other->high) return false;
    if (low < other->low) return true;
    if (low > other->low) return false;
    return subcategory < other->subcategory;
}