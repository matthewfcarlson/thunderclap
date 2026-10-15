struct V {
    char b[64];
    V(const void*, const void*);
};
class SpriteParticleEmitter {
  public:
    char pad[0xec];
    char x[64];
    virtual V* vfunc_22(V* out);
};
V* SpriteParticleEmitter::vfunc_22(V* out) {
    V tmp((char*)this + 0x40, x);
    *out = tmp;
    return out;
}