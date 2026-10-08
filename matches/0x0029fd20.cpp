struct Obj { void Method(int v, void* self); };
extern Obj* gObject;
struct Caller { void Target(int value); };
void Caller::Target(int value) { gObject->Method(value, this); }
