extern "C" void* __cdecl Cast(void*, int, const char*, const char*, int);
namespace content {
namespace LoadInventory {
class DynamicCasterBase {
  public:
    virtual void* vfunc_0(void*);
};
class DynamicCaster {
  public:
    virtual void* vfunc_0(void*);
};
} // namespace LoadInventory
} // namespace content
void* content::LoadInventory::DynamicCaster::vfunc_0(void* p) {
    return Cast(p, 0, (const char*)0x48d5bc, (const char*)0x4cf460, 0);
}
