class pddiBaseContext { public: char pad[0x54]; void* member; bool vfunc_79(); };
bool pddiBaseContext::vfunc_79() { return *((bool*)((char*)member + 4)); }