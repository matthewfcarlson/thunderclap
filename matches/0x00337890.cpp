class Ref { public: virtual void F(int); };
class Obj { public: unsigned a; unsigned b; Ref* member; void Go(); };
void Obj::Go() { a = 0x434578; if (member) member->F(1); }