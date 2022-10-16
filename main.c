/*
 *	PostgreSQL definitions for Query plan.
 *
 *	contrib/optimizer/main.c
 *
 */

#include "postgres.h"

//  #include "common/hashfn.h"
#include "optimizer/planner.h"
#include "planner.h"


#include "utils/builtins.h"
#include "utils/formatting.h"
#include "utils/varlena.h"


#define OP_VERSION "0.1"

PG_MODULE_MAGIC;

/*
 * This is the trigger that protects us from orphaned large objects
 */
PG_FUNCTION_INFO_V1(op_version);

Datum
op_version(PG_FUNCTION_ARGS)
{
	PG_RETURN_TEXT_P(cstring_to_text(OP_VERSION));
}

/* shared library initialization function */
void
_PG_init(void)
{
    // if (!process_shared_preload_libraries_in_progress)
    // {
    //     ereport(ERROR, (errmsg("Citus can only be loaded via shared_preload_libraries"),
    //                     errhint("Add citus to shared_preload_libraries configuration "
    //                             "variable in postgresql.conf in master and workers. Note "
    //                             "that citus should be at the beginning of "
    //                             "shared_preload_libraries.")));
    // }


    /*
     * Perform checks before registering any hooks, to avoid erroring out in a
     * partial state.
     *
     * In many cases (e.g. planner and utility hook, to run inside
     * pg_stat_statements et. al.) we have to be loaded before other hooks
     * (thus as the innermost/last running hook) to be able to do our
     * duties. For simplicity insist that all hooks are previously unused.
     */
    if (planner_hook != NULL )
    {
        ereport(ERROR, (errmsg("op extension has to be loaded first"),
                        errhint("Place this op extension at the beginning of "
                                "shared_preload_libraries.")));
    }

    /* intercept planner */
    planner_hook = my_planner;


}

