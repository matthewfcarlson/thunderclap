void InitGlobal();
struct X { int value; void Set(int); };
void X::Set(int x) { value = x; InitGlobal(); }