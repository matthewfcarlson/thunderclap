extern "C" char DAT_00400854[];
class CSPHulkPropLoader {
  public:
    virtual ~CSPHulkPropLoader();
    CSPHulkPropLoader* Init();
};
extern void Initialize();
CSPHulkPropLoader* CSPHulkPropLoader::Init() {
    Initialize();
    *(void**)this = (void*)((int)DAT_00400854);
    return this;
}