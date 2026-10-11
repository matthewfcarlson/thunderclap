extern "C" char DAT_0042f190[];
class ParticleAllocator {
  public:
    int mVptr;
    int mValue;
    ParticleAllocator();
};
ParticleAllocator::ParticleAllocator() {
    mValue = 0;
    mVptr = ((int)DAT_0042f190);
}