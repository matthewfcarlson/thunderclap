class Resource {
  public:
    Resource(const char*, int);
};
extern Resource g_resource;
extern "C" void __cdecl cleanup();
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl initResource() {
    g_resource.Resource::Resource("sound/rsd", 0);
    atexit(cleanup);
}