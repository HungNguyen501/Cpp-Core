include Common/MakefileUtils

.PHONY: help
all: help
help: Makefile
	@echo "Go to one of following modules and then type $(GREEN)make help$(NO_COLOR) for helper:" \
	"$(GREEN)\n.\n├── Algorithms\n├── DataStructure\n├── DynamicProgramming\n└── ProblemSolving$(NC)"
