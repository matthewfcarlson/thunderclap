class ParticleAllocator {
  public:
    int mVptr;
    int mValue;
    ParticleAllocator();
};
ParticleAllocator::ParticleAllocator() {
    mValue = 0;
    mVptr = 0x42f190;
}