class Base { public: void Init(); };
class Thing : public Base { char pad[0x40]; volatile int a; volatile int b; volatile int c; volatile int d; volatile int e; public: void Run(); };
void Thing::Run() { Init(); c=0; b=0; a=0; d=0x3f800000; e=0; }