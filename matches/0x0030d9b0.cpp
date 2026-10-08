// Same code shape as 0x0030d980 (propagated; names are from that function)
struct Sub { void Process(); };
struct Item { char pad[0x10]; Sub* sub; };
struct Owner { char pad[4]; Item* begin; Item* end; void Target(); };
void Owner::Target() {
    Item* p = begin;
    if (p <= end) {
        do {
            p->sub->Process();
            Item* old = p;
            p = (Item*)((char*)p + 0x14);
            if (old == end) break;
        } while (1);
    }
}