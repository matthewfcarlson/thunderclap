extern float gZero;
class Obj { char pad[0x160]; public: int Find(int); char* Get(int); };
char* Obj::Get(int arg) { int i = Find(arg); if (i == -1) return (char*)&gZero; return (char*)this + 0x160 + i * 0x18; }