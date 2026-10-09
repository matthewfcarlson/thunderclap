class Source { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual unsigned int Get(); };
struct Scratch { char data[12]; void Build(void*, unsigned int); };
class Owner { public: char pad[0x18]; Source* source; void Process(Scratch*, unsigned int); void Run(unsigned int a, unsigned int b, unsigned int c, unsigned int d); };
void Owner::Run(unsigned int a, unsigned int b, unsigned int c, unsigned int d) { if (source) { unsigned int x = source->Get(); Scratch temp; temp.Build(&a, x); Process(&temp, d); } }
