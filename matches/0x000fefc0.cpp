class Obj { public: char pad[0x110]; int value; int Target(); };
extern void __cdecl Init(Obj*, int*);
int Obj::Target() {
    if (value == 0) Init(this, &value);
    return value;
}