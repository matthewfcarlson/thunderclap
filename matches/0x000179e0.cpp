class H { public: void* f(); void* g(); unsigned int h(int); };
class CDeathAction { public: char pad[0x1c]; H* m; bool vfunc_6(int); };
bool CDeathAction::vfunc_6(int) { H* a = m; void* b=a->f(); H* c=(H*)b; void* d=c->g(); H* e=(H*)d; e->h(1); return false; }