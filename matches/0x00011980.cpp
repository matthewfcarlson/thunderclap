struct Base_11980 {
    virtual void F();
    void* GetVtable();
};

void* Base_11980::GetVtable() {
    return *(void**)this;
}
