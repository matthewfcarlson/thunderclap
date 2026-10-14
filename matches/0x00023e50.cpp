struct Sub_23e50 {
    void* Run();
};
struct Obj_23e50 {
    char pad[0x80];
    Sub_23e50 sub;
    void* Target();
};
void* Obj_23e50::Target() {
    return sub.Run();
}
