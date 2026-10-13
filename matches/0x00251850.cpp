struct Sub {
    void* Get() { return (char*)this + 0x1c; }
};

void* __fastcall FUN_00251850(Sub* self) {
    return (char*)self + 0x1c;
}
