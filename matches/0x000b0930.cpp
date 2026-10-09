extern float zeroValue;
struct Entry { int count; void* ptr; };
class Obj { public: char pad[0x290]; Entry entries[13]; void* Get(int a, int b); };
void* Obj::Get(int a, int b) { if (a < 0 || a >= 13) return &zeroValue; if (b >= 0 && b < entries[a].count) return (char*)entries[a].ptr + b * 32; return &zeroValue; }