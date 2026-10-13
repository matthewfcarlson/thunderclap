struct Sub {
    void* Run();
};
struct Obj {
    char pad[0x80];
    Sub sub;
    void* Target();
};
void* Obj::Target() {
    return sub.Run();
}
