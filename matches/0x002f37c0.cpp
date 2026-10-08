class X { char pad[0x44]; public: int m; int __fastcall f(); };
int __fastcall X::f() { return m + 0x24; }