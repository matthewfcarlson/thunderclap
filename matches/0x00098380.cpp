struct Obj { unsigned int x[16]; void Run(unsigned int); };
struct Helper { void Init(Obj*, unsigned int); };
void Obj::Run(unsigned int arg) { Obj local; ((Helper*)&local)->Init(this, arg); *this = local; }