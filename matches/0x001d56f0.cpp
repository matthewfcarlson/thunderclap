struct Inner { char pad[0x1c]; int* data; };
class C { public: char pad[0x90]; Inner* m; int f(int index); };
int C::f(int index) { return m->data[index]; }