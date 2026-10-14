struct D3DResource {};
void __stdcall D3DResource_AddRef(D3DResource*);
void __stdcall D3DResource_Release(D3DResource*);
struct Owner_326300 {
    char pad[0x10];
    D3DResource* resource;
    void Set(D3DResource*);
};
void Owner_326300::Set(D3DResource* value) {
    if (value)
        D3DResource_AddRef(value);
    if (resource)
        D3DResource_Release(resource);
    resource = value;
}