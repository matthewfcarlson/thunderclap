struct X { void Call(); X* Target(); };
X* X::Target() { Call(); return this; }