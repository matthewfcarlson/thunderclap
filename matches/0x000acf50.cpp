struct Item { void Apply(int); };
struct Owner { char pad[0x10]; int count; Item** items; void Apply(int); };
void Owner::Apply(int value) { int i=0; if (count>0) do { items[i]->Apply(value); ++i; } while(i<count); }