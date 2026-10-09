class Item { public: virtual void f0(); virtual void Release(); };
extern void Free(void*);
class Container { public: Item* first; Item** begin; Item** end; void Clear(); };
void Container::Clear() { if(first) { first->Release(); first=0; } unsigned int n=(unsigned int)(((char*)end-(char*)begin)>>2); unsigned int i=0; if(n<=0) { } else do { Item** q=begin+i; if(*q) { (*q)->Release(); *q=0; } ++i; } while(i<n); if(begin) Free(begin); }