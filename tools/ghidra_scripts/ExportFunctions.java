// Export every function as CSV: address,size,name,calls,xrefs,is_thunk,chunks
// size spans the entry point to the end of the last body range (functions can be split into chunks).
// Run: analyzeHeadless build/ghidra hulk -process default.xbe -noanalysis -readOnly \
//        -scriptPath tools/ghidra_scripts -postScript ExportFunctions.java build/functions.csv
//@category Hulk

import java.io.PrintWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

public class ExportFunctions extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String out = getScriptArgs().length > 0 ? getScriptArgs()[0] : "build/functions.csv";
        try (PrintWriter w = new PrintWriter(out)) {
            w.println("address,size,name,calls,xrefs,is_thunk,chunks");
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                int calls = f.getCalledFunctions(monitor).size();
                int xrefs = getReferencesTo(f.getEntryPoint()).length;
                long size = f.getBody().getMaxAddress().subtract(f.getEntryPoint()) + 1;
                int chunks = f.getBody().getNumAddressRanges();
                w.printf("0x%08x,%d,\"%s\",%d,%d,%d,%d%n", f.getEntryPoint().getOffset(), size,
                    f.getName(true).replace("\"", "\"\""), calls, xrefs, f.isThunk() ? 1 : 0, chunks);
            }
        }
        println("wrote " + out);
    }
}
