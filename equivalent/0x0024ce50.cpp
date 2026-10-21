// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 6/6)
// FUN_0024ce50 @ 0x0024ce50
#include "compat/ptr.h"
extern "C" double __cdecl sqrt(double);
struct Vec3_24ce50 { float x,y,z; };
struct Source_24ce50 { float x,y,z; char pad[12]; float vx,vy,vz; };
hulk_freg __cdecl FUN_0024ce50(const Source_24ce50* a, const Vec3_24ce50* b) {
    double x=(double)a->x-b->x;
    double y=(double)a->y-b->y;
    double z=(double)a->z-b->z;
    float distance=(float)sqrt(z*z+y*y+x*x);
    double negativeDot=y*a->vy*-1.0f-z*a->vz-x*a->vx;
    double length=sqrt((double)a->vx*a->vx+(double)a->vy*a->vy+(double)a->vz*a->vz);
    float ratio=(float)(negativeDot/(length*distance));
    if(distance==0.0f || ratio>0.0f) return 1.0f;
    if(ratio > -0.58f) return 1.0f-ratio*-0.862069f;
    return 0.5f;
}
