class RenderObjectLoader_2df850 {
  public:
    RenderObjectLoader_2df850();
    virtual void Fn();
    int unused;
};
class OldPrimGroupLoader : public RenderObjectLoader_2df850 {
  public:
    OldPrimGroupLoader();
    virtual void Fn();
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
};
OldPrimGroupLoader::OldPrimGroupLoader() : a(0), b(0), c(-1), d(-1), e(0), f(0), g(0) {}