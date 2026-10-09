class C { char pad[0x90]; int a,b,c; public: bool F(const int* p); };
bool C::F(const int* p) { a=p[0]; b=p[1]; c=p[2]; return true; }