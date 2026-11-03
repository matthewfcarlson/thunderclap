// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000f7f60 @ 0x000f7f60
// cl-flags: /GS
#include "gen/owners.h"
extern "C" void __cdecl FUN_00294c70(int src, char* dst, int size);


void owners::Printer_f7f60::FUN_000f7f60(int src, int a2, int a3, int a4, int a5, int a6) {
    struct Frame {
        char text[0x400];
    } fr;
    FUN_00294c70(src, fr.text, 0x200);
    FUN_000f7d60(fr.text, a2, a3, a4, a5, a6);
}
