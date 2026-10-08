// Print decompiled C for functions given as script args (addresses or Namespace::name).
// Run: analyzeHeadless build/ghidra hulk -process default.xbe -noanalysis -readOnly \
//        -scriptPath tools/ghidra_scripts -postScript DecompileFunction.java 0x4274d8 'choreo2::Driver::vfunc_3'
//@category Hulk

import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Symbol;

public class DecompileFunction extends GhidraScript {
    @Override
    protected void run() throws Exception {
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        for (String arg : getScriptArgs()) {
            Function f = null;
            if (arg.startsWith("0x")) {
                f = getFunctionContaining(toAddr(arg));
            } else {
                for (Symbol s : currentProgram.getSymbolTable().getSymbols(arg.substring(arg.lastIndexOf("::") + 2))) {
                    if (s.getName(true).equals(arg)) f = getFunctionAt(s.getAddress());
                }
            }
            if (f == null) { println("not found: " + arg); continue; }
            DecompileResults r = di.decompileFunction(f, 60, monitor);
            println("// " + f.getName(true) + " @ " + f.getEntryPoint() + "\n" + r.getDecompiledFunction().getC());
        }
        di.dispose();
    }
}
