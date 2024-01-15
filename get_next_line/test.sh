#!/bin/bash

print_color() {
    local color="$1"
    local message="$2"
    local reset_color=$(tput sgr0)
    echo -e "${color}${message}${reset_color}"
}

print_test_result() {
	local label="$1"
	local expected="$2"
	local actual="$3"

	if [ "$expected" == "$actual" ]; then
		print_color "$(tput setaf 2)" "$label: ✓"
	else
		print_color "$(tput setaf 3)" "Expected: $expected"
		print_color "$(tput setaf 3)" "Actual: $actual"
		fi
}

print_color "$(tput setaf 7)" " ---------------------- "
print_color "$(tput setaf 7)" "  TESTING THE MAKEFILE  "
print_color "$(tput setaf 7)" " ---------------------- "

# MAKE THE LIBRARY
make > /dev/null
if [ $? -eq 0 ]; then
	print_color "$(tput setaf 2)" "make: ✓"
else
	print_color "$(tput setaf 1)" "make: x"
fi

# CLEAN THE OBJECT FILES
make clean > /dev/null
if [ $? -eq 0 ]; then
	print_color "$(tput setaf 2)" "clean: ✓"
else
	print_color "$(tput setaf 1)" "clean: x"
fi

# CLEAN THE OBJECT FILES AND LIBRARY
make fclean > /dev/null
if [ $? -eq 0 ]; then
	print_color "$(tput setaf 2)" "fclean: ✓"
else
	print_color "$(tput setaf 1)" "fclean: x"
fi

# MAKE THE LIBRARY AGAIN
make re > /dev/null
if [ $? -eq 0 ]; then
	print_color "$(tput setaf 2)" "re: ✓"
else
	print_color "$(tput setaf 1)" "re: x"
fi







make fclean > /dev/null
