extern "C" void destroyChooser(void*);
namespace pure3d {
class LightsChooserCache {
  public:
    virtual ~LightsChooserCache();
    void baseDtor();
    char pad[0x20];
    void* mPtr;
};

LightsChooserCache::~LightsChooserCache() {
    destroyChooser(mPtr);
    baseDtor();
}
} // namespace pure3d
