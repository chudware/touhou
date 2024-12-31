ifndef GBDK_HOME
	GBDK_HOME = /Users/anon/Downloads/gbdk/
endif

LCC = $(GBDK_HOME)bin/lcc 

# GBDK_DEBUG = ON
ifdef GBDK_DEBUG
	LCCFLAGS += -debug -v
endif


# You can set the name of the .gb ROM file here
PROJECTNAME = _touhou

SRCDIR      = src
OBJDIR      = build
RESDIR      = res
BINS	    = $(OBJDIR)/$(PROJECTNAME).gb
CSOURCES    = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(RESDIR),$(notdir $(wildcard $(dir)/*.c)))
ASMSOURCES  = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.s)))
OBJS       = $(CSOURCES:%.c=$(OBJDIR)/%.o) $(ASMSOURCES:%.s=$(OBJDIR)/%.o)

# Colors for the output
GREEN  := \033[1;32m
YELLOW := \033[1;33m
RED    := \033[1;31m
RESET  := \033[0m

all:	prepare $(BINS)

compile.bat: Makefile
	@echo "REM Automatically generated from Makefile" > compile.bat
	@make -sn | sed y/\\//\\\\/ | sed s/mkdir\ -p\/mkdir\/ | grep -v make >> compile.bat

# Compile .c files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	@echo "$(GREEN)Compiling $(YELLOW)$<$(GREEN) to $(YELLOW)$@$(RESET)"
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# Compile .c files in "res/" to .o object files
$(OBJDIR)/%.o:	$(RESDIR)/%.c
	@echo "$(GREEN)Compiling $(YELLOW)$<$(GREEN) to $(YELLOW)$@$(RESET)"
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# Compile .s assembly files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.s
	@echo "$(GREEN)Compiling $(YELLOW)$<$(GREEN) to $(YELLOW)$@$(RESET)"
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# If needed, compile .c files in "src/" to .s assembly files
# (not required if .c is compiled directly to .o)
$(OBJDIR)/%.s:	$(SRCDIR)/%.c
	@echo "$(GREEN)Compiling $(YELLOW)$<$(GREEN) to $(YELLOW)$@$(RESET)"
	$(LCC) $(LCCFLAGS) -S -o $@ $<

# Link the compiled object files into a .gb ROM file
$(BINS):	$(OBJS)
	@echo "$(GREEN)Linking $(YELLOW)$(BINS)$(RESET)"
	$(LCC) $(LCCFLAGS) -o $(BINS) $(OBJS)

prepare:
	@echo "$(GREEN)Creating output directory $(YELLOW)$(OBJDIR)$(RESET)"
	mkdir -p $(OBJDIR)

clean:
	@echo "$(RED)Cleaning up$(RESET)"
#	rm -f  *.gb *.ihx *.cdb *.adb *.noi *.adb *.noi *.map
	rm -f  $(OBJDIR)/*.*
