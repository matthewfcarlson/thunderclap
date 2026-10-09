struct Part { void Init(); };
struct CollisionOBB { unsigned v; char pad[0x38]; Part b; char pad2[0x3f]; Part a; void Target(); void Base(); };
void CollisionOBB::Target() { v=0x4317dc; a.Init(); b.Init(); Base(); }
