struct Inner {
    char m[0x9c];
};
struct Obj {
    Inner* Get();
};
Inner* Obj::Get() {
    return (Inner*)((char*)this + 0x9c);
}