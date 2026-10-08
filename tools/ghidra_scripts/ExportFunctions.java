// Export every function as CSV: address,size,name,calls,xrefs,is_thunk
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
            w.println("address,size,name,calls,xrefs,is_thunk");
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                int calls = f.getCalledFunctions(monitor).size();
                int xrefs = getReferencesTo(f.getEntryPoint()).length;
                // Size = contiguous body from the entry point (ignores non-contiguous chunks).
                long size = f.getBody().getRangeContaining(f.getEntryPoint()).getLength();
                w.printf("0x%08x,%d,\"%s\",%d,%d,%d%n", f.getEntryPoint().getOffset(), size,
                    f.getName(true).replace("\"", "\"\""), calls, xrefs, f.isThunk() ? 1 : 0);
            }
        }
        println("wrote " + out);
    }
}
