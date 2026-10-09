extern void* g_ptr;
void* __cdecl Swap(void* value) {
    void* old = g_ptr;
    g_ptr = value;
    return old;
}