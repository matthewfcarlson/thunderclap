class Y { public: virtual void G(int); char pad[4]; int count; void F(); };
void Y::F() { int *p = &count; *p = *p - 1; if (*p == 0) { *p = 0x5dc; G(1); } }
