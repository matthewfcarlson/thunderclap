extern int vftable;
class Sub { public: void Init(); };
class Obj { public: char pad[8]; Sub sub; void Init(); };
void Obj::Init() { sub.Init(); *(int*)this = (int)&vftable; }