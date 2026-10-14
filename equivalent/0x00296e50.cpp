// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 12/12)
// pure3d::scenegraph::BoundingVolumeUpdater::vfunc_0 @ 0x00296e50
struct Matrix;
struct Vec_296e50 { float x,y,z; void FUN_0022d210(Matrix*); };
struct Bounds_296e50 { Vec_296e50 low,high; void FUN_000a87f0(Vec_296e50*); void FUN_000f6e90(Bounds_296e50*); };
struct Drawable { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void refresh(); char pad[16]; Bounds_296e50 bounds; };
struct Node { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual int type(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual Matrix* matrix(); char pad[20]; Drawable* drawable; char pad2[12]; unsigned char active; };
namespace pure3d { namespace scenegraph { struct BoundingVolumeUpdater { virtual bool vfunc_0(Node*); virtual void vfunc_1(); unsigned char initialized; char pad[3]; Bounds_296e50 bounds; }; 
bool BoundingVolumeUpdater::vfunc_0(Node* node) {
 if (!node) return true;
 if (node->type()==4) return node->active!=0;
 if (node->type()==16) {
 Drawable* d=node->drawable;
 if(d) {
 Matrix* m=node->matrix();
 d->refresh();
 Bounds_296e50 b=d->bounds;
 b.low.FUN_0022d210(m);
 b.high.FUN_0022d210(m);
 if(initialized==1) { bounds.FUN_000a87f0(&b.low); bounds.FUN_000a87f0(&b.high); }
 else { bounds.FUN_000f6e90(&b); initialized=1; }
 }
 }
 return true;
}
} }