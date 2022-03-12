CPP=g++
LIBS=-lsqlite3
CPPFLAGS=-g -Wall -Wextra $(LIBS)

CHOC_AN_MAIN=src/main.cpp
TESTS=TestDate.cpp

TEST_MAINS=$(addprefix tests/,$(TESTS))
TEST_BINS=$(subst .cpp,,$(TEST_MAINS))
MAINS=$(CHOC_AN_MAIN) $(TEST_MAINS)
SOURCES=$(filter-out $(MAINS),$(wildcard src/*.cpp))
OBJECTS=$(subst .cpp,.o,$(SOURCES))
HEADERS=$(wildcard src/*.h)

choc-an: $(OBJECTS) $(HEADERS) $(CHOC_AN_MAIN)
	$(CPP) $(CPPFLAGS) $(OBJECTS) $(CHOC_AN_MAIN) -o $@

test: $(OBJECTS) $(HEADERS) $(TEST_BINS)
	@for main_file in $(TEST_MAINS); do \
		exec_file=$${main_file%%.cpp} ;\
		echo == $${main_file} == ;\
		$${exec_file} ;\
	done

$(TEST_BINS): $(OBJECTS) $(HEADERS) $(TEST_MAINS)
	$(CPP) $(CPPFLAGS) $(OBJECTS) $@.cpp -o $@

.PHONY: clean test-all
clean:
	rm -fv choc-an
	rm -fv $(subst .cpp,,$(TEST_MAINS))
	rm -fv $(OBJECTS)

