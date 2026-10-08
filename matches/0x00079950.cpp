class C { char pad[0x374c]; void* arr[1]; int lookup(int); public: bool f(int); };
bool C::f(int x) { int i=lookup(x); if(i==-1) return false; return *(int*)((char*)arr[i]+0x10)!=0x13; }