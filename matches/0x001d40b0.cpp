struct Obj { char pad[8]; int value; void Init(); void Target(); };
void DoThing(int, int, int);
void Obj::Target() { Init(); DoThing(value, 2, 0); }