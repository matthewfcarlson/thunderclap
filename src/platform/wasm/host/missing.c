/* Game functions the tree has no block for yet ("not yet verified" in their TU) that the port reaches: stand-ins
 * by address until the tree verifies them (each names its TU line; to move into the tree, docs/wasm-port.md). */
#include "hulk_host.h"

/* 0x0031acc0 pure3d__d3dDisplay__VBlankCallback (src/platform/xbox/pure3d/d3dDisplay.cpp): counts vertical blanks
 * into the word pure3d::d3dDisplay::vfunc_14 reads (0x0055549c) */
FFG(0031acc0) { UNUSED; (*(uint32_t*)PTR(0x0055549c))++; }
