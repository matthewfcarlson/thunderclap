class ParticleGenerator { public: virtual void a(); virtual void b(); };
class ParticlePlaneGenerator : public ParticleGenerator { public: char pad[0x4c - 4]; void vfunc_9(); };
void ParticlePlaneGenerator::vfunc_9() {
    *(int*)((char*)this + 0x4c) = 0x3f800000;
    *(int*)((char*)this + 0x50) = 0x3f800000;
    *(int*)((char*)this + 0x54) = 0x3f800000;
    *(int*)((char*)this + 0x58) = 0x3f800000;
    *(int*)((char*)this + 0x5c) = 0x3f800000;
}