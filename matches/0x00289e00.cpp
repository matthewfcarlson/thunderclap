typedef unsigned int size_t;
void* operator new(size_t);
class ChannelLoader_289e00 {
  public:
    ChannelLoader_289e00() throw();
    virtual void Init();
    char pad[0x48];
};
class SimpleChunkHandler_289e00 {
  public:
    virtual void Other();
    int a;
    void* b;
    int c, d;
    SimpleChunkHandler_289e00() : a(0), b((void*)0x121000), c(0), d(0) {}
};
class AnimationLoader_289e00 : public SimpleChunkHandler_289e00 {
  public:
    AnimationLoader_289e00();
    virtual void Dummy();
    ChannelLoader_289e00* anim;
    int e, f, g;
};
AnimationLoader_289e00::AnimationLoader_289e00() : anim(0), e(0), f(-1), g(0) {
    anim = new ChannelLoader_289e00;
    anim->Init();
}
