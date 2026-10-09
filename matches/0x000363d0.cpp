struct Sub { void Run(); };
struct Thing { char pad[0xdc]; Sub sub; char pad2[0x1e58-0xdc-4]; int field; void f(); };
void Thing::f() { sub.Run(); field = 0; }