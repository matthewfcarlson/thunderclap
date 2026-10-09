class Holder { public: int first(); int second(); };
class SuckInPropsAction { public: char pad[0x20]; Holder* holder; bool vfunc_3(void*, void*); };
bool SuckInPropsAction::vfunc_3(void*, void*) {
    int value = holder->first();
    if (value == 0) return false;
    if (((Holder*)value)->second() == 0) return false;
    return true;
}