struct A_17c40 {
    void* first();
};
struct B_17c40 {
    B_17c40* second();
    void act(int);
};
class CSnapToWallAction {
  public:
    char pad[0x1c];
    A_17c40* mFirst;
    B_17c40* mSecond;
    bool vfunc_7(int);
};
bool CSnapToWallAction::vfunc_7(int arg) {
    B_17c40* b = (B_17c40*)mFirst->first();
    b = b->second();
    if (*(char*)((char*)mSecond + 0x24)) {
        b->act(1);
        return true;
    }
    b->act(3);
    return true;
}