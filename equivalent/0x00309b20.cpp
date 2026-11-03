// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00309b20 @ 0x00309b20
#include "gen/owners.h"
 bool owners::Node_309b20::FUN_00309b20(owners::Node_309b20* other) { int valueToFind = value; if (valueToFind >= other->value) return false; while (other->value > valueToFind) { other = other->next; if (!other) return false; if (other->value == valueToFind) return true; } return false; }