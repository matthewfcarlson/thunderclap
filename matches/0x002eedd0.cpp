class Inner { public: void First(); void Second(void*, void*, int); };
class Obj { public: char pad[0xb0]; void Run(void*); };
void Obj::Run(void* arg) {
    ((Inner*)this)->First();
    ((Inner*)((char*)this + 0xb0))->Second((char*)this + 0x2c, arg, 0);
}