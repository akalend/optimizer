# contrib/op/Makefile

MODULE_big = optimizer

OBJS =  \
	analyzejoins.o \
	createplan.o \
	initsplan.o \
	planagg.o \
	planmain.o \
	planner.o \
	setrefs.o \
	subselect.o \
	main.o

EXTENSION = op
DATA = op--0.1.sql 
PGFILEDESC = "my optimizer"

# REGRESS = op

ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
else
subdir = contrib/$(MODULES)
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif
