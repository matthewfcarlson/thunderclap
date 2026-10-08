struct Thing { char pad[0xaa4]; void* Get(); };
void* Thing::Get() { return (char*)this + 0xaa4; }