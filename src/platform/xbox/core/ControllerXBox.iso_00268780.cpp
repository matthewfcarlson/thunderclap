// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00268300..0x00269680 (kind game, layer platform/xbox, confidence high), dominant class core::ControllerXBox
// (tree_prelude.h: not needed)


// 0x00268780 core::ControllerXBox::vfunc_21 (38 B): matches/0x00268780.cpp [isolated: conflict: XInputClose; on include/gen/ and not mergeable]
// sym: ?vfunc_21@ControllerXBox@core@@UAEXH@Z
#include "gen/core.h"

extern void __stdcall XInputClose(int);

void core::ControllerXBox::vfunc_21(int p) {
    if (this->f_08)
        XInputClose(this->f_08);
    this->f_08 = p;
}

