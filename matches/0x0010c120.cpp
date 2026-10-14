struct Inner_10c120 {
    int x;
};
struct Obj_10c120 {
    char pad[12];
    Inner_10c120& Get();
};

Inner_10c120& Obj_10c120::Get() {
    return *(Inner_10c120*)((char*)this + 12);
}
