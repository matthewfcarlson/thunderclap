// Same code shape as 0x001c6c40 (propagated; names are from that function)
class Part { public: void Cleanup(); };
class Thing { public: int v; Part part; Thing* Run(unsigned char flags); };
void DeleteThing(Thing*);
Thing* Thing::Run(unsigned char flags) {
    part.Cleanup();
    if (flags & 1) DeleteThing(this);
    return this;
}