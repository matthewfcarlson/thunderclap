class A { public: virtual void f(); virtual void g(); };
void FUN_000187d0(A **p) { if (*p) { (*p)->g(); *p = 0; } }