ProjectName := Commons
CC := clang++
CFLAGS := -std=c++17

define run_module
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
	@echo "Choose a module to run in project $(ProjectName), syntax: make -B {module}"
	@ls -d */ | awk '{print "- ", $$1}'
endef

define runClean
	@-find ./ -type f -name "*.o"  -exec rm -rf {} +
	@-find ./ -type d -name "main.dSYM"  -exec rm -rf {} +
	@-find ./ -type d -name "main.o.dSYM"  -exec rm -rf {} +
endef
