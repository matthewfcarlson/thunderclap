class Thing { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); char pad[0x10]; int field; void Prepare(int); };
class Item { public: Thing* owner; void Apply(int, int); };
class Manager { char pad[0x24]; public: int count; Item* Get(int); void Run(int); };
void Manager::Run(int arg)
{
    if (arg) {
        Item* p = Get(arg);
        if (p) {
            int value = p->owner->field;
            p->owner->Prepare(value + 1);
            p->Apply(value, arg);
            ++count;
        }
    }
}