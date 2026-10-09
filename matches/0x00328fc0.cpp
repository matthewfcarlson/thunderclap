class Obj { public: int a; int b; Obj* Init(); Obj* Target(int, int); };
Obj* Obj::Target(int p2, int p3) { a = p2; b = p3; Init(); return this; }
