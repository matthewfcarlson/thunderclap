class Target { char pad[0x10]; int a,b,c; public: void Set(const int *p); };
void Target::Set(const int *p) { a=p[0]; b=p[1]; c=p[2]; }