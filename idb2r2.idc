#include <idc.idc>

static idb2r2_functions(seg) {
    auto ea = seg;
    auto teststr;
    while (ea != BADADDR) {
        auto function_name = GetFunctionName(ea);
        auto function_cmt = get_func_cmt(ea, 1);
        
        if (function_name != 0) {
            teststr = sprintf("sub_%X", ea);
            if( teststr != function_name )
            {
                Message("af %s @ 0x%X\n", function_name, ea);
            }
        }
        /*
        if (function_cmt) {
            Message("%s\n", function_cmt);
        }
        */
        ea = NextFunction(ea);
    }
}

static idb2r2_comments(seg) {

}

static main(void) {
    Message("Beginning of idb2r2\n");
    Message("===================\n");
    
    auto first_seg = get_first_seg();
    if (first_seg != BADADDR) {
        idb2r2_functions(first_seg);
    } else {
        Message("Could not retrieve address of first segment!\n");
    }

    return 0;
}