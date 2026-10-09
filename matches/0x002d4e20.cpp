namespace pure3d {
class Ref { public: virtual void AddRef(); virtual void Release(); };
class ParticleEmitter { public: char pad[0x90]; Ref* mRef; void vfunc_31(Ref*); };
void ParticleEmitter::vfunc_31(Ref* p) {
 if (p != mRef) {
  if (p) p->AddRef();
  if (mRef) mRef->Release();
  mRef = p;
 }
}
}