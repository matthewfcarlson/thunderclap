struct Temp { char pad[8]; int value; int extra; void Init(); void Fin(); };
extern void Free(void *);
class Obj { public: bool Do(int, Temp *); bool Run(int); };
bool Obj::Run(int arg) { Temp t; t.Init(); t.value = 0; bool r = Do(arg, &t); if (t.value) { Free((void *)t.value); t.value = 0; } t.Fin(); return r; }
