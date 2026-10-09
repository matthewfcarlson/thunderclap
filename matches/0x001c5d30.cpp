class Ref { public: virtual void f0(); virtual void Release(); };
class Base { public: void Finish(); };
class Target : public Base { public: char pad[8]; Ref* volatile b; Ref* volatile a; void Clear(); };
void Target::Clear() { Ref* x = a; if (x) x->Release(); a = 0; x = b; if (x) x->Release(); b = 0; Finish(); }