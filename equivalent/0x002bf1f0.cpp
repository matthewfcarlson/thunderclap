// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// pure3d::ImageFont::vfunc_9 @ 0x002bf1f0
#include "compat/ptr.h"
#include "gen/pure3d.h"

namespace pure3d {   }
int pure3d::ImageFont::vfunc_9(hulk_intptr __p0) { const unsigned short * text = (const unsigned short *)__p0;
 if (!text) return 0; int result = this->f_18; int increment = (*(int *)&this->f_20) + result; while (*text) { if (*text == 10) result += increment; ++text; } return result; }
