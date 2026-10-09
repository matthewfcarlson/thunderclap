class Obj { public: char pad[0x14]; int a; int b; int c; int d; int e; void Init(); Obj* Target(); };
Obj* Obj::Target() { Init(); a=0; b=0; c=0; d=0x3f800000; e=0x3f800000; return this; }