// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 22/22)
// pure3d::scenegraph::Node::vfunc_15 @ 0x00295d40
extern unsigned int DAT_0052cb98;
namespace pure3d { namespace scenegraph {
struct Node {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual unsigned int vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual unsigned int vfunc_11(); virtual Node* vfunc_12(unsigned int); virtual void vfunc_13(); virtual void vfunc_14(); virtual Node* vfunc_15(int,int,int,unsigned int,unsigned int); virtual void vfunc_16(); virtual void vfunc_17();
 int field4; int key1; int key2; int field16; Node* parent;
};
Node* Node::vfunc_15(int a,int b,int direction,unsigned int mask,unsigned int match) {
 unsigned int flags=vfunc_5();
 if ((mask & flags) && key1==a && key2==b) {
  if (DAT_0052cb98==match) return this;
  ++DAT_0052cb98;
 }
 if(direction==1) {
  if(parent) return parent->vfunc_15(a,b,1,mask,match);
 } else if(direction==2) {
  unsigned int index=0;
  if(vfunc_11()>0) {
   do {
    Node* child=vfunc_12(index);
    if(child) { Node* result=child->vfunc_15(a,b,2,mask,match); if(result) return result; }
    ++index;
   } while(index<vfunc_11());
  }
 }
 return 0;
}
}}
