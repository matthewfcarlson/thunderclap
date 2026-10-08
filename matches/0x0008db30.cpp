class CSPHulkPropLoader { public: virtual ~CSPHulkPropLoader(); CSPHulkPropLoader* Init(); };
extern void Initialize();
CSPHulkPropLoader* CSPHulkPropLoader::Init() { Initialize(); *(void**)this = (void*)0x400854; return this; }