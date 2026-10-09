struct Entry { unsigned a,b; };
struct Table { unsigned count; char pad[24]; Entry* entries; };
struct Owner { Table* table; int index; unsigned long long get(); };
unsigned long long Owner::get() {
 int i=index;
 if (i < 0 || (unsigned)i >= table->count) return 0;
 Entry* e=table->entries+i;
 return *(unsigned long long*)e;
}