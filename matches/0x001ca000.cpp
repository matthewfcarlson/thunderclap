class C { public: void helper(int, int, int); int target(int, int); };
int C::target(int a, int b) { helper(10, a, b); return (int)this; }