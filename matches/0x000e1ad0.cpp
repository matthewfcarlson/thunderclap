class Obj { char pad[0x3c]; int *items; public: void Set(int index, int value); };
extern int __cdecl Make(int value);
void Obj::Set(int index, int value) { if (items) items[index] = Make(value); }