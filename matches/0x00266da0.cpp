// Same code shape as 0x002474f0 (propagated; names are from that function)
extern void* g_ptr;
void* __cdecl Swap(void* value) {
    void* old = g_ptr;
    g_ptr = value;
    return old;
}