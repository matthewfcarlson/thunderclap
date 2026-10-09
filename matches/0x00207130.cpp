class Obj { public: int GetCount(int); void DoThing(int); bool Target(); };
bool Obj::Target() {
    int n = GetCount(0);
    if (n > 0) {
        DoThing(n);
        return true;
    }
    return false;
}