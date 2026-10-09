class ShaderCallbackVisitor {
  public:
    virtual void V();
    void* mThing;
    ShaderCallbackVisitor(void* p);
};
ShaderCallbackVisitor::ShaderCallbackVisitor(void* p) : mThing(p) {
    if (p)
        ((ShaderCallbackVisitor*)p)->V();
}