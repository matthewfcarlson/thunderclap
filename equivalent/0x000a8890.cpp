// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 6/6)
// FUN_000a8890 @ 0x000a8890
// FUN_000a8890 @ 0x000a8890
extern "C" double __cdecl sqrt(double);
struct Sphere_a8890 { float x,y,z,radius; };
struct Box_a8890 { float minX,minY,minZ,maxX,maxY,maxZ; Sphere_a8890* FUN_000a8890(Sphere_a8890* out); };
Sphere_a8890* Box_a8890::FUN_000a8890(Sphere_a8890* out) {
 float x,y,z,r;
 if (!(minX > maxX) && !(minY > maxY) && !(minZ > maxZ)) {
  volatile float hx = (maxX-minX)*0.5f;
  volatile float dz = maxZ-minZ;
  double hy = ((double)maxY-minY)*0.5;
  double hz = (double)dz*0.5;
  x = hx+minX; y = (float)(hy+minY); z = (float)(hz+minZ);
  double zy = hz*hz+hy*hy; // keep the original's summation order
  r = (float)sqrt(zy+(double)hx*hx);
 } else { x=y=z=r=0.0f; }
 out->radius=r; out->x=x; out->y=y; out->z=z;
    return out;
}
