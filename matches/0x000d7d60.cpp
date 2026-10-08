struct Sub { void Clear(); };
struct Obj { char pad[0x10]; Sub sub; char pad2[0x23]; unsigned char flag; Obj* Run(); };
Obj* Obj::Run() { sub.Clear(); flag = 0; return this; }