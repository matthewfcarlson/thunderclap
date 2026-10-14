// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 24/24)
// FUN_00026e30 @ 0x00026e30
struct Vec_26e30 { float x,y,z; };
struct Position_26e30 { bool FUN_00059a50(Vec_26e30*); };
struct Category { char pad[0x18]; int index; };
struct Entity { char pad[0x10]; Position_26e30* position; char pad2[0x108]; Category* category; };
struct Registry_26e30 { Entity* FUN_00059c10(int); };
struct Root_26e30 { char pad[0x44]; Registry_26e30* registry; };
extern "C" double __cdecl sqrt(double);
struct Target_26e30 { Root_26e30* root; char pad[8]; int count; int ids[69]; Entity* self; int FUN_00026e30(float radius,int* output,int size); };
int Target_26e30::FUN_00026e30(float radius,int* output,int size) {
 for(int j=0;j<size;++j) output[j]=0;
 int result=0; Vec_26e30 origin;
 if(!self->position->FUN_00059a50(&origin)) return 0;
 for(int i=0;i<count;++i) {
 Entity* e=root->registry->FUN_00059c10(ids[i]);
 if(!e || e==self) continue;
 if(radius>0.0f) {
 Vec_26e30 p;
 if(!e->position->FUN_00059a50(&p)) continue;
 double dx=(double)p.x-origin.x, dz=(double)p.z-origin.z;
 if(sqrt(dx*dx+dz*dz)>radius) continue;
 }
 Category* c=e->category;
 if(c && c->index>=0 && c->index<size) ++output[c->index];
 ++result;
 }
 return result;
}