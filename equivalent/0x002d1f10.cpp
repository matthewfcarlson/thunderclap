// STATUS: equivalent (tools/equiv.py level 3: 30 inputs, branch coverage 8/8)
// pure3d::SpriteParticleUpdater::vfunc_5 @ 0x002d1f10
namespace pure3d {
struct Particle { float position[3]; char pad[32]; float age; };
struct ParticleSystem { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual unsigned s13(); char pad[0x1c4]; Particle** particles; };
typedef void (__cdecl *Update)(float, ParticleSystem*, Particle*);
typedef void (__cdecl *Finish)(float, ParticleSystem*, Particle*, float*);
struct SpriteParticleUpdater {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(float dt, ParticleSystem* system);
char pad[4]; Update a; Update b; Update c; Finish d;
};
void SpriteParticleUpdater::vfunc_5(float dt, ParticleSystem* system) {
 if (!(dt > 0.0f)) return;
 unsigned count = system->s13();
 for(unsigned i=0;i<count;++i) {
 Particle* p=system->particles[i];
 float oldPosition[3]; oldPosition[0]=p->position[0]; oldPosition[1]=p->position[1]; oldPosition[2]=p->position[2];
 float step=dt;
 if(!(p->age >= 0.0f)) { step=dt-p->age; p->age=step; } else { p->age=dt+p->age; }
 a(step,system,p); b(step,system,p); c(step,system,p); d(step,system,p,oldPosition);
 }
}
}
