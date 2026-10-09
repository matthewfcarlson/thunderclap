class Child { public: };
class Thing { public: void Do(Child*); };
class Owner { public: char pad[0x448]; Child* child; Thing* Get(); void Set(Child*); };
void Owner::Set(Child* arg) { Thing* t = Get(); Child* old = child; t->Do(old); child = arg; }
