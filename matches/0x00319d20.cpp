struct Obj_319d20 {
    char pad[0xa0];
    int value;
    bool IsTwo();
};
bool Obj_319d20::IsTwo() {
    if (value == 2)
        return true;
    return false;
}
