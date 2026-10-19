struct ThisWrap_000efc80 {
    void* FUN_000e7620(void*);
    void* FUN_000efc80(void* arg);
};
struct Obj_efc80 {
    char pad[0x9ac];
    void* value;
};
void* ThisWrap_000efc80::FUN_000efc80(void* arg) {
    return ((Obj_efc80*)this->FUN_000e7620(arg))->value;
}
