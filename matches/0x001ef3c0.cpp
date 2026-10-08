struct Entry { char pad[8]; void Init(void*); };
struct Helper { void Finish(); };
class Owner { public: char pad[0x40]; int count; void Run(void*, void*); };
void Owner::Run(void* a, void* b) {
    if (count < 8) {
        ((Entry*)((char*)this + count * 8))->Init(&a);
        ++count;
    }
    ((Helper*)&a)->Finish();
}