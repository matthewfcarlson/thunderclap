// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// pure3d::SpriteParticleEmitter::vfunc_10 @ 0x002d4650
namespace pure3d {
struct Matrix { float elements[16]; };
struct SpriteParticleEmitter {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual Matrix* vfunc_22(Matrix*);
 char pad[16];
 float minX,minY,minZ,maxX,maxY,maxZ,centerX,centerY,centerZ,radius;
};
void SpriteParticleEmitter::vfunc_10() {
 Matrix temp;
 Matrix* transform = vfunc_22(&temp);
 float x = transform->elements[12];
 float y = transform->elements[13];
 float z = transform->elements[14];
 maxZ = z + 0.01f;
 maxX = x + 0.01f;
 maxY = y + 0.01f;
 minZ = z - 0.01f;
 minX = x - 0.01f;
 minY = y - 0.01f;
 centerX=x; centerY=y; centerZ=z; radius=0.01f;
}
}
