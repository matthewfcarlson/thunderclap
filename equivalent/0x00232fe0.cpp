// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00232fe0 @ 0x00232fe0
#include "gen/owners.h"
 owners::Node_232fe0* owners::Node_232fe0::FUN_00232fe0() { if (boundary) return boundary; owners::Node_232fe0* node = this; while (node) { if (node->value) return node->value; node = node->parent; } return 0; }