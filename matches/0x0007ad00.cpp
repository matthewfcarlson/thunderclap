struct Obj { char pad[0x3800]; int vals[1]; int helper(int); int target(int); };
int Obj::target(int arg) { int i = helper(arg); if (i >= 0) return vals[i]; return 0; }