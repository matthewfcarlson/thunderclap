// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000a8890 @ 0x000a8890
extern "C" double __cdecl sqrt(double);
struct Sphere { float x,y,z,radius; };
struct Box { float minX,minY,minZ,maxX,maxY,maxZ; void FUN_000a8890(Sphere* out); };
void Box::FUN_000a8890(Sphere* out) {
 float x,y,z,r;
 if (!(minX > maxX) && !(minY > maxY) && !(minZ > maxZ)) {
  float hx = (maxX-minX)*0.5f;
  float dz = maxZ-minZ;
  double hy = ((double)maxY-minY)*0.5;
  double hz = (double)dz*0.5;
  x = hx+minX; y = (float)(hy+minY); z = (float)(hz+minZ);
  r = (float)sqrt(hz*hz+hy*hy+(double)hx*hx);
 } else { x=y=z=r=0.0f; }
 out->radius=r; out->x=x; out->y=y; out->z=z;
}