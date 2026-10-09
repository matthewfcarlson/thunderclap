// Targeted fixes for the MSVC 7.1 compile errors models hit most (mined with tools/compile_errors.py).
// Appended to compile-error replies so a retry doesn't repeat the same mistake.

const HINTS: Record<string, string> = {
	C4234: "MSVC 7.1 rejects __thiscall in function-pointer types. Declare the class with virtual methods and call obj->Method() instead of casting.",
	C2039: "Declare that member in the class (with the right type and offset), or call a method you declared.",
	C2065: "Every identifier must be declared before use: add an extern declaration, a member, or a local.",
	C3861: "Declare the function before calling it (a prototype, or a member function declared in the class).",
	C2761: "A member function can be declared only once inside its class; define it outside the class as Class::Name(...) { ... }.",
	C2509: "Define only member functions that are declared in the class body, with the same signature.",
	C2535: "The same member function is declared twice; keep one declaration.",
	C2556: "Declaration and definition must have identical return type and parameters.",
	C2511: "The out-of-class definition's signature doesn't match any declaration in the class. Make them identical (including const).",
	C2600: "To define a constructor/destructor/operator=, declare it in the class first (e.g. virtual ~X();).",
	C2533: "Constructors have no return type.",
	C2577: "Destructors have no return type and return nothing. For a deleting destructor, declare virtual ~X(); and define X::~X() { ... }.",
	C2229: "Zero-length arrays aren't allowed; remove the padding member when the gap is 0 bytes.",
	C2118: "A padding array has a negative size; recompute the offsets (pad = next_offset - (previous_offset + previous_size)).",
	C2673: "'this' only exists in member functions. Make the function a member (Class::Func) if the asm uses ecx as this.",
	C2440: "Use an explicit cast to the exact target type, or fix the declared type of the variable or member.",
	C2227: "The left side of -> must be a pointer to a declared class/struct; declare the type of that member.",
	C2660: "The call's argument count doesn't match the declaration. Declare the prototype with the right parameters.",
	C2040: "The same name is declared with different pointer levels; make the declarations agree.",
	C2371: "The same name is declared with two different types; keep one declaration.",
	C2248: "Members are private by default in a class; put them under public:.",
	C2059: "Syntax error: MSVC 7.1 is pre-C++11 (no auto, nullptr, override, enum class, range-for, static_assert, brace init).",
	C2143: "Syntax error: MSVC 7.1 is pre-C++11 (no auto, nullptr, override, enum class, range-for, brace init). Check for a missing ';' after a class body.",
	C2447: "Usually a stray ';' or an unbalanced brace before a function body.",
	C1075: "Unbalanced braces: a '{' is never closed.",
};

export function compileHints(report: string, max = 3): string {
	const codes = [...new Set([...report.matchAll(/error (C\d{4})/g)].map((m) => m[1]))];
	const lines = codes.filter((c) => HINTS[c]).slice(0, max).map((c) => `Hint (${c}): ${HINTS[c]}`);
	return lines.length ? "\n" + lines.join("\n") : "";
}
