// STATUS: equivalent (tools/equiv.py level 3: 61 inputs, branch coverage 25/26, incomplete)
// physics::HairclubPhysicsObject::vfunc_35 @ 0x00309680
struct Strand {
 char pad[0x28];
 float weight;
 char extra[4];
 unsigned char active;
 char tail[3];
 void FUN_002fcb80(float scale);
};
namespace physics {
struct HairclubPhysicsObject {
 char pad[0x1f8];
 Strand* strands;
 int count;
 void FUN_00309410();
 void vfunc_35(float value);
};
}
void physics::HairclubPhysicsObject::vfunc_35(float value) {
 double total = 0.0f;
 int n = count;
 for (int i=0;i<n;++i) {
  if (strands[i].active) total += strands[i].weight;
 }
 if (total > 0.0f) {
  value = (float)(value / total);
  if(n > 0) {
   for(int i=0;i<count;++i) {
    Strand* s = &strands[i];
    if(s->active) {
     s->weight = s->weight * value;
     s->FUN_002fcb80(value);
    }
   }
  }
 }
 FUN_00309410();
}
