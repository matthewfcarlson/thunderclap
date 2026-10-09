struct Helper { void* f(); void* g(); };
class ShieldArcAction { public: char pad[0x1c]; void* member1c; Helper* member20; bool vfunc_3(void*, void*); };
bool ShieldArcAction::vfunc_3(void*, void*) {
    if (member20) {
        void* a = member20->f();
        void* b = ((Helper*)a)->g();
        *(int*)((char*)b + 0x628) = *(int*)((char*)member1c + 0x10);
    }
    return false;
}