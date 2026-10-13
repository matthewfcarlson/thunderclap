struct Inner {
    int x;
};
struct Obj {
    char pad[12];
    Inner& Get();
};

Inner& Obj::Get() {
    return *(Inner*)((char*)this + 12);
}
