// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/7)
// pure3d::ParticlePlaneGenerator::vfunc_8 @ 0x002d2b40
#include "decls/data/game/global.h"

namespace pure3d { struct ParticlePlaneGenerator { char pad[0x4c]; float a,b,c,d,e; float vfunc_8(unsigned int index); }; }
float pure3d::ParticlePlaneGenerator::vfunc_8(unsigned int index) {
    switch (index) {
    case 1: return c;
    case 2: return d;
    case 3: return e;
    case 4: return a;
    case 5: return b;
    default: return (*(float*)&DAT_003f32e0);
    }
}