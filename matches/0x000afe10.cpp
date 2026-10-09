class Other { public: void Run(int); };
class Thing { public: char pad[5]; unsigned char flag; Other* p; void Set(int); };
void Thing::Set(int value) { if (flag != (unsigned char)value) { if (p) p->Run(value); flag = (unsigned char)value; } }