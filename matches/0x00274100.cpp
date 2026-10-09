// Same code shape as 0x002737f0 (propagated; names are from that function)
struct Sub { virtual void f(); virtual void g(); };
struct V { virtual void f(); virtual void g(); };
struct Inner { void *v; Sub sub; char pad[16]; int ref; };
struct Request { void *v; char pad[4]; Inner *p; void run(); };
void Request::run() { v=(void*)0x42b99c; p->sub.f(); --p->ref; p->sub.g(); ((V*)p)->g(); v=(void*)0x42b914; }
