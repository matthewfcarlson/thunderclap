class IRefCount {
  public:
    virtual ~IRefCount() throw();
};
IRefCount::~IRefCount() throw() {}
void ReleaseRef(int);
class ShadowMeshTopology : public IRefCount {
  public:
    int pad04[3];
    int m10;
    int m14;
    virtual ~ShadowMeshTopology() throw();
};
ShadowMeshTopology::~ShadowMeshTopology() throw() {
    ReleaseRef(m10);
    ReleaseRef(m14);
}
