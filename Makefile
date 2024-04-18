ProjectName := Commons
CC := clang++
CFLAGS := -std=c++17
RED := \033[1;31m
GREEN := \033[1;32m
BLUE := \033[0;34m
NC := \033[0m# No Color

define runTarget
	@echo "Running" $@ "..."
	@$(CC) $(CFLAGS) $@/main.cpp -o $@/main.o && ./$@/main.o
endef

define validateTargets
	@targetList=$$(grep -E '^[a-zA-Z0-9]*:$$' $< | grep -oE "[a-zA-Z0-9]*" | grep -vE "^(clean|validateTargets|all|help)$$") \
		&& moduleList=$$(ls -d */ | awk '{print "- ", $$1}' | grep -oE "[a-zA-Z0-9]*") \
		&& diffTargets=$$(echo $${targetList[@]} $${moduleList[@]} | tr ' ' '\n' | sort | uniq -u) \
		&& if [ "$${diffTargets}" != "" ]; then echo $${diffTargets} | tr ' ' '\n'; \
			else echo "Cool, All modules is added to Makefile."; fi
endef

define runHelp
	@echo "$(RED)Command helps"
	@echo "$(GREEN)$$ make validateTargets$(NC): Verify all modules is added to Makefile"
	@echo "$(GREEN)$$ make clean$(NC): Clean output files and dependencies."
	@echo "$(GREEN)$$ make -B {module}$(NC): Run one of following targets in project $(ProjectName):"
	@ls -d */ | awk '{printf("    $(BLUE)%d. %s$(NC)\n", NR, substr($$1, 0, length($$1) - 1));}'
endef

define runClean
	@-find ./ -type f -name "*.o"  -exec rm -rf {} +
	@-find ./ -type d -name "main.dSYM"  -exec rm -rf {} +
	@-find ./ -type d -name "main.o.dSYM"  -exec rm -rf {} +
endef
