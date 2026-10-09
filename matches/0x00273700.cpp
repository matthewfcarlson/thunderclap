struct I0 { virtual void f(); virtual void g(); };
struct I3 { virtual void a(); virtual void b(); virtual void c(); virtual void d(int); };
struct Obj { void* v; I0 sub; char pad[0x10]; int count; };
struct FileCompletionRequest { char pad[0xc]; Obj* p; I3* q; int arg; void vfunc_7(); };
void FileCompletionRequest::vfunc_7() { p->sub.f(); --p->count; p->sub.g(); q->d(arg); }