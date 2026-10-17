// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::PolySkin::vfunc_6 @ 0x002b78c0
namespace pure3d {
struct Child {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(int, int);
};
struct DrawableContainer {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 void vfunc_6(int, int);
};
struct PolySkin : DrawableContainer {
 char pad[0x68];
 Child* first;
 Child* second;
 void vfunc_6(int a, int b);
};
void PolySkin::vfunc_6(int a, int b) {
 if (first) first->vfunc_6(a,b);
 if (second) second->vfunc_6(a,b);
 DrawableContainer::vfunc_6(a,b);
}
}