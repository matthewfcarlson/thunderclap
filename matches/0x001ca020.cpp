class C { public: void callee(int, int, int); C* wrap(int, int); };
C* C::wrap(int a, int b) { callee(11, a, b); return this; }
