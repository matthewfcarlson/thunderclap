extern const float gZero;
struct Inner { char pad[0x10]; void *Get(); float Calc(); };
struct Owner { char pad[0x10]; Inner *m; float f(); };
float Owner::f() { Inner *p=m; void *q=p->Get(); if (!q) return gZero; return ((Inner*)((char*)q+0x10))->Calc(); }