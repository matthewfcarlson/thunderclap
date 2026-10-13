// STATUS: equivalent (tools/equiv.py level 3: 795 inputs, branch coverage 16/16)
// FUN_001dcdf0 @ 0x001dcdf0
struct Vec3 { float x,y,z; };
struct Entry { Vec3* FUN_001d6b40(); };
struct Object {
 char padding[0x1e620];
 Entry* entries[128];
 int count;
 bool FUN_001dcdf0(float x,float y,float z,float radius);
};
bool Object::FUN_001dcdf0(float x,float y,float z,float radius) {
 float minX=x-radius,minY=y-radius,minZ=z-radius;
 float maxX=x+radius,maxY=y+radius,maxZ=z+radius;
 for(int i=0;i<count;++i) {
  Vec3 p=*entries[i]->FUN_001d6b40();
  if(p.x>minX && p.x<maxX && p.y>minY && p.y<maxY && p.z>minZ && p.z<maxZ) return true;
 }
 return false;
}