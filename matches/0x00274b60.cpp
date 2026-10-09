extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
struct Manager { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(void*); };
extern Manager* g_manager;
extern char g_lock[1];
extern void* request_vftable[];
struct Request { void** vt; Request* vfunc_0(unsigned char); };
Request* Request::vfunc_0(unsigned char param) {
 vt = request_vftable;
 if (param & 1) {
  FUN_0026d850(g_lock);
  g_manager->e(this);
  FUN_0026d840(g_lock);
 }
 return this;
}