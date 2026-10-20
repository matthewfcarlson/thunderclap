// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 12/12)
// FUN_0030f6b0 @ 0x0030f6b0
void* __cdecl FUN_0008d6d0(unsigned int);
void __cdecl FUN_0030eba0();
void __stdcall FUN_00011520(void*, unsigned int, int, void (__cdecl*)());
struct Node {
 int index; Node* parent; int unused; int count; char pad[176];
 void FUN_0030ec20(int);
 void FUN_0030ec70(Node*);
};
struct Source_30f6b0 {
 virtual void retain();
 char pad[12]; int count; char pad2[20]; unsigned short* parents;
};
namespace physics { struct Pose {
 virtual void slot0();
 int state; Source_30f6b0* source; Node* nodes;
 Pose(Source_30f6b0*);
}; }
physics::Pose::Pose(Source_30f6b0* s) {
 state=0;
 if (!s) {source=0;nodes=0;return;}
 source=s; source->retain();
 int n=source->count;
 unsigned int* memory=(unsigned int*)FUN_0008d6d0((unsigned int)n*192+4);
 Node* array=0;
 if(memory) {memory[0]=n;array=(Node*)(memory+1);FUN_00011520(array,192,n,&FUN_0030eba0);}
 nodes=array;
 for(int i=1;i<n;++i) {
 nodes[i].index=i;
 Node* parent=&nodes[source->parents[i]];
 nodes[i].parent=parent;
 parent->FUN_0030ec20(parent->count+1);
 }
 for(int j=1;j<n;++j) {
 Node* child=&nodes[j];
 Node* parent=&nodes[source->parents[j]];
 parent->FUN_0030ec70(child);
 }
}