class Inner { public: void Call(int); };
class Holder { public: char pad[0x44]; Inner* inner; };
class Obj { public: Holder* owner; int pad[2]; int count; int values[1]; void Target(int unused); };
void Obj::Target(int unused) {
    for (int i = 0; i < count; ++i)
        owner->inner->Call(values[i]);
}
