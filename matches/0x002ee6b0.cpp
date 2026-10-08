class Obj { public: char pad[0x6c]; unsigned char flag; void callee(int); void target(int); };
void Obj::target(int arg) { callee(arg); flag = 1; }