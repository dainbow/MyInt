CC = g++

CXXFLAGS  = -c -g -std=c++17 -Wall -Wextra -Weffc++ -Wc++0x-compat -Wc++11-compat -Wc++14-compat -Waggressive-loop-optimizations -Walloc-zero -Walloca -Walloca-larger-than=8192 -Warray-bounds -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wdangling-else -Wduplicated-branches -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Wformat-overflow=2 -Wformat-truncation=2 -Wlarger-than=8192 -Wvla-larger-than=8192 -Wlogical-op -Wmissing-declarations -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Wredundant-decls -Wrestrict -Wshadow -Wsign-promo -Wstack-usage=8192 -Wstrict-null-sentinel -Wstrict-overflow=2 -Wstringop-overflow=4 -Wsuggest-attribute=noreturn -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wnarrowing -Wno-old-style-cast -Wvarargs -Waligned-new -Walloc-size-larger-than=1073741824 -Walloc-zero -Walloca -Walloca-larger-than=8192 -Wcast-align -Wdangling-else -Wduplicated-branches -Wformat-overflow=2 -Wformat-truncation=2 -Wmissing-attributes -Wmultistatement-macros -Wrestrict -Wshadow=global -Wsuggest-attribute=malloc -fcheck-new -fsized-deallocation -fstack-check -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer 
CXXFLAGS += -O2
LDFLAGS = 

SRCDIRS = ./src/
BINDIR = ./bin/

SOURCES = $(shell find $(SRCDIRS)*.cpp)
OBJECTS = $(addprefix $(BINDIR),$(notdir $(SOURCES:.cpp=.o)))
DEPENDENCES = $(addsuffix .d,$(OBJECTS))

EXECUTABLE = MyInt.out

$(EXECUTABLE): $(OBJECTS)
	@$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(BINDIR)%.o: $(SRCDIRS)%.cpp
	@$(CC) -MMD -MF $@.d $(CXXFLAGS) $< -o $@

-include $(DEPENDENCES)

.PHONY: all, clean, mkdirs

all: $(EXECUTABLE)

mkdirs:
	mkdir $(BINDIR) $(SRCDIRS)

clean: 
	rm $(OBJECTS) $(DEPENDENCES)
