extern "C" void __cdecl Format(char*, unsigned int, const char*, void*);
class Inner { public: void Next(void*); };
class Obj { public: char pad[8]; Inner inner; char pad2[0x10]; void Run(void*); };
void Obj::Run(void* arg) {
    Format((char*)this + 0x20, 0x20, "%s", arg);
    inner.Next(arg);
}