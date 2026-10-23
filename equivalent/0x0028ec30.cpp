// STATUS: equivalent (tools/equiv.py level 3: 20024 inputs, branch coverage 12/12)
// pure3d::DefaultChannelHandler::vfunc_4 @ 0x0028ec30
#include "gen/pure3d.h"

struct Channel_28ec30 { unsigned FUN_00266c30(); };
namespace pure3d { struct DefaultChannelHandler_nv_28ec30 {
    int FUN_0028c580(Channel_28ec30*,void*,void*);
    int FUN_0028c6b0(Channel_28ec30*,void*,void*);
    int FUN_0028c7e0(Channel_28ec30*,void*,void*);
    int FUN_0028c910(Channel_28ec30*,void*,void*);
    int FUN_0028e160(Channel_28ec30*,void*,void*);
    int FUN_0028cd80(Channel_28ec30*,void*,void*);
    int FUN_0028ea80(Channel_28ec30*,void*,void*);
    int FUN_0028ceb0(Channel_28ec30*,void*,void*);
    int FUN_0028cfd0(Channel_28ec30*,void*,void*);
}; }
int pure3d::DefaultChannelHandler::vfunc_4(int __p0, int __p1, int __p2) { Channel_28ec30 * c = (Channel_28ec30 *)__p0; void * a = (void *)__p1; void * b = (void *)__p2;

unsigned index = c->FUN_00266c30() - 0x121100;
if(index > 20) return 0;
switch(index) {
case 14: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028c580(c,a,b);
case 0: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028c6b0(c,a,b);
case 1: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028c7e0(c,a,b);
case 2: case 3: case 4: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028c910(c,a,b);
case 5: case 17: case 18: case 19: case 20: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028e160(c,a,b);
case 6: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028cd80(c,a,b);
case 7: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028ea80(c,a,b);
case 8: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028ceb0(c,a,b);
case 9: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028cfd0(c,a,b);
default: return 0;
}
}
