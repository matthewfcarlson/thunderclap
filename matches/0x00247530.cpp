struct V { void* a; void (__cdecl *b)(void*, int); };
extern V* g;
void target(int x) { g->b(g, x); }
