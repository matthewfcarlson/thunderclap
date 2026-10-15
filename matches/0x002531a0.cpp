namespace audio {
class Base {
  public:
    virtual void v0();
    Base();
};
class SeqEventVarPosDist : public Base {
  public:
    char pad[4];
    float a, b;
    SeqEventVarPosDist() : Base(), a(1.0f), b(100.0f) {}
    static void* operator new(unsigned int, void* p) { return p; }
};
class SeqEventVarPosDistType {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual SeqEventVarPosDist* vfunc_3();
};
} // namespace audio
extern void* alloc(void*);
extern char heap;
audio::SeqEventVarPosDist* audio::SeqEventVarPosDistType::vfunc_3() {
    void* p = alloc(&heap);
    audio::SeqEventVarPosDist* q;
    if (p)
        q = new (p) audio::SeqEventVarPosDist;
    else
        q = 0;
    return q;
}
