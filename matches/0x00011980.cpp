struct Base {
    virtual void F();
    void* GetVtable();
};

void* Base::GetVtable() {
    return *(void**)this;
}
