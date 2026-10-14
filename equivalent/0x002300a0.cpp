// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002300a0 @ 0x002300a0
extern "C" double __cdecl sqrt(double);
struct Vec { float x,y,z; };
struct Line { Vec start,end; double distance(const Vec* p); };
double Line::distance(const Vec* p) {
 double dx=(double)end.x-start.x, dy=(double)end.y-start.y;
 volatile float dz=end.z-start.z;
 volatile float t=(((double)p->z-start.z)*dz+((double)p->y-start.y)*dy+((double)p->x-start.x)*dx)/((double)dz*dz+dx*dx+dy*dy);
 volatile float sx=(float)(dx*t);
 volatile float x=sx+start.x;
 volatile float y=(float)(dy*t+start.y);
 double z=(double)dz*t+start.z;
 double px=(double)p->x-x, py=(double)p->y-y, pz=(double)p->z-z;
 return sqrt(pz*pz+py*py+px*px);
}