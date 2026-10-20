class ShadowMeshTopology_2b37e0 {
  public:
    virtual ~ShadowMeshTopology_2b37e0() throw();
};
ShadowMeshTopology_2b37e0::~ShadowMeshTopology_2b37e0() throw() {}
void ReleaseRef(int);
class ShadowMeshTopology : public ShadowMeshTopology_2b37e0 {
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
