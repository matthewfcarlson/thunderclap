// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::scenegraph::VisibilityNode::vfunc_6 @ 0x002969b0
namespace pure3d { namespace scenegraph {
struct Node {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(int,int);
};
struct BranchNode : Node { char pad[8]; void vfunc_6(int,int); };
struct VisibilityNode : BranchNode { char pad2[0x2c - sizeof(BranchNode)]; Node* child; void vfunc_6(int,int); };
void VisibilityNode::vfunc_6(int a,int b) {
 if (!(*((unsigned char*)this + 0x10) & 1)) {
  if (child) child->vfunc_6(a,b);
  BranchNode::vfunc_6(a,b);
 }
}
}}