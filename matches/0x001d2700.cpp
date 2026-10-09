void ReleaseThing(void*);
class Obj { char pad[8]; void* mPtr; public: void Clear(); };
void Obj::Clear() { if (mPtr) { ReleaseThing(mPtr); mPtr = 0; } }