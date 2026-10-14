struct Child_afe80 {
    void cleanup();
};
struct Obj_afe80 {
    char pad[5];
    bool flag;
    char pad2[2];
    Child_afe80* ptr;
    void run();
};
void tail();
void Obj_afe80::run() {
    if (ptr)
        ptr->cleanup();
    if (flag)
        tail();
}
