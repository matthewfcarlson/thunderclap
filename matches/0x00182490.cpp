struct Helper_182490 {
    Helper_182490* first();
    char* second();
};
class PropThrowAction {
  public:
    char pad[0x20];
    Helper_182490* member;
    bool vfunc_3(int, int);
};
bool PropThrowAction::vfunc_3(int, int) {
    if (!member)
        return false;
    Helper_182490* p = member->first();
    *(p->second() + 0x1f51) = 1;
    return true;
}
