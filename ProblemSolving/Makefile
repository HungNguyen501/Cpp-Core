ProjectName := ProblemSolving
CC := clang++
CFLAGS := -std=c++11

define run_module
	@echo "Running" $@ "..."
	@$(CC) $(CFLAGS) $@/main.cpp -o $@/main.o && ./$@/main.o
endef

FindLargestValueInTreeRow:
	@$(call run_module)

HanoiTower:
	@$(call run_module)

LongestPalindromicSubstring:
	@$(call run_module)

MaximumSumSubarray:
	@$(call run_module)

MergeTwoSortedArrays:
	@$(call run_module)

MergeKSortedArrays:
	@$(call run_module)

RadioTransmitters:
	@$(call run_module)

ReadLargeFile:
	@$(call run_module)

RotateImage:
	@$(call run_module)

SmallestSubarrayWithKDistinctNumbers:
	@$(call run_module)

clean:
	@-find ./ -type f -name "*.o"  -exec rm -rf {} +

.PHONY: help
all: help
help: Makefile
	@echo "Choose a module to run in project $(ProjectName), syntax: make -B {module}"
	@ls -d */ | awk '{print "- ", $$1}'
