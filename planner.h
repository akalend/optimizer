
/*-------------------------------------------------------------------------
 *
 * planner.h
 *	  prototypes for planner.c.
 *
 * Note that the primary entry points for planner.c are declared in
 * optimizer/optimizer.h, because they're intended to be called from
 * non-planner code.  Declarations here are meant for use by other
 * planner modules.
 *
 * Portions Copyright (c) 1996-2021, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/optimizer/planner.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef OP_PLANNER_H
#define OP_PLANNER_H



extern PlannedStmt *my_planner(Query *parse, const char *query_string,
									int cursorOptions,
				 					ParamListInfo boundParams);


#endif							/* OP_PLANNER_H */
