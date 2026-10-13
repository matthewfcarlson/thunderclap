// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 20/20)
// FUN_001ae040 @ 0x001ae040
struct Vec3 { float x,y,z; };
struct Node { unsigned int unused; int links[2]; unsigned char pad; unsigned char ratings[2]; unsigned char rating; };
struct Manager { Node* FUN_001b5800(int id); bool FUN_001b65f0(int id, unsigned int slot); Vec3* FUN_001b5a20(Vec3* out, int id); };
extern "C" double __cdecl sqrt(double);
struct Search { Manager* manager; unsigned int minRating; unsigned int maxRating; int FUN_001ae040(const Vec3* pos, int id, int unused); };
int Search::FUN_001ae040(const Vec3* pos, int id, int unused) {
 Node* root=manager->FUN_001b5800(id);
 int result=0; float best=0.0f;
 if(!root) return 0;
 for(unsigned int slot=1;slot<3;++slot) {
  int neighbor=root->links[slot-1];
  if(neighbor==-1) {
   if(!manager->FUN_001b65f0(id,slot)) continue;
   neighbor=root->links[slot-1];
   if(neighbor==-1) continue;
  }
  Node* node=manager->FUN_001b5800(neighbor);
  if(!node) { root->links[slot-1]=-1; continue; }
  if(node->rating>maxRating || root->ratings[slot-1]<minRating) continue;
  Vec3 temp; Vec3* point=manager->FUN_001b5a20(&temp,neighbor);
  double dx=(double)point->x-pos->x, dy=(double)point->y-pos->y, dz=(double)point->z-pos->z;
  double distance=sqrt(dx*dx+dz*dz+dy*dy);
  if(best==0.0f || distance<best) { best=(float)distance; result=neighbor; }
 }
 return result;
}