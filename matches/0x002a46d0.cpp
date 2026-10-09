class A { public: virtual void F(); virtual void G(); };
void __stdcall FUN_002a46d0(A** param_1, A* param_2) { if (param_2) param_2->F(); if (*param_1) (*param_1)->G(); *param_1 = param_2; }