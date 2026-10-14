struct Inner_1924f0 {
    char m[0x9c];
};
struct Obj_1924f0 {
    Inner_1924f0* Get();
};
Inner_1924f0* Obj_1924f0::Get() {
    return (Inner_1924f0*)((char*)this + 0x9c);
}