struct A { void* first(); };
struct B { B* second(); void act(int); };
class CSnapToWallAction {
public:
    char pad[0x1c];
    A* mFirst;
    B* mSecond;
    bool vfunc_7(int);
};
bool CSnapToWallAction::vfunc_7(int arg) {
    B* b = (B*)mFirst->first();
    b = b->second();
    if (*(char*)((char*)mSecond + 0x24)) {
        b->act(1);
        return true;
    }
    b->act(3);
    return true;
}