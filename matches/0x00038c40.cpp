class Item { public: virtual void f(); virtual void Release(); };
struct Entry { Item* volatile p; volatile unsigned char flag; char pad[0x33]; };
class Owner { public: char pad[0x1ed8]; Entry entries[3]; void Clear(); };
void Owner::Clear() { Entry* q=entries; int n=3; do { q->flag=0; Item* x=q->p; if(x) { x->Release(); q->p=0; } ++q; } while(--n); }