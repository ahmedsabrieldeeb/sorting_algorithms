# flags for make command
MAKEFLAGS += -s

# compiler arguments
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89

# basic source files and headers
SRC = print_list.c print_array.c sort.h

# bubble sort build
SRC_BUBBLE = 0-main.c 0-bubble_sort.c
TARGET_BUBBLE = bubble

# inertion sort build
SRC_INSERTION = 1-main.c 1-insertion_sort_list.c
TARGET_INSERTION = insert

# selection sort build
SRC_SELECTION = 2-main.c 2-selection_sort.c
TARGET_SELECTION = select

# quick sort build
SRC_QUICK = 3-main.c 3-quick_sort.c
TARGET_QUICK = quick

# phony my targets to avoid naming conflicts
.PHONY: all bubble quick insert select clean


# GUI for building (main menu)
all:
	@valid_choice=""
	@while [ -z "$$valid_choice" ]; do \
\
\
		echo "\nAvailable targets:\n"; \
		echo "1. bubble"; \
		echo "2. quick"; \
		echo "3. insert"; \
		echo "4. select"; \
		echo "5. clean"; \
		echo "6. Exit"; \
		echo ""; \
		read -p "Enter the target to build: " choice; \
\
\
		case $$choice in \
			1) $(MAKE) bubble ;; \
			2) $(MAKE) quick ;; \
			3) $(MAKE) insert ;; \
			4) $(MAKE) select ;; \
			5) $(MAKE) clean ;; \
			6) echo "Bye Bye..."; exit ;; \
			*) echo "\n!! Invalid choice !!\n";; \
		esac; \
	done


##
# building
##
bubble:
$(TARGET_BUBBLE): $(SRC_BUBBLE)
	$(CC) $(CFLAGS) $(SRC) $(SRC_BUBBLE) -o $(TARGET_BUBBLE)

quick:
$(TARGET_QUICK): $(SRC_QUICK)
	$(CC) $(CFLAGS) $(SRC) $(SRC_QUICK) -o $(TARGET_QUICK)

insert:
$(TARGET_INSERTION): $(SRC_INSERTION)
	$(CC) $(CFLAGS) $(SRC) $(SRC_INSERTION) -o $(TARGET_INSERTION)

select:
$(TARGET_SELECTION): $(SRC_SELECTION)
	$(CC) $(CFLAGS) $(SRC) $(SRC_SELECTION) -o $(TARGET_SELECTION)

# GUI for cleaning
clean:
	@valid_choice=""
	@while [ -z "$$valid_choice" ]; do \
\
\
		echo "\nClean Options:"; \
		echo "1. Clean all targets"; \
		echo "2. Clean specific target"; \
		echo "3. Back"; \
		echo ""; \
		read -p "Enter your choice: " choice; \
\
\
		case $$choice in \
			1) \
				rm -f $(TARGET_BUBBLE) $(TARGET_QUICK) $(TARGET_INSERTION) $(TARGET_SELECTION);; \
			2) \
				valid_specific_choice=""; \
				while [ -z "$$valid_specific_choice" ]; do \
\
\
					echo "\nChoose the target to clean:"; \
					echo "1. bubble"; \
					echo "2. quick"; \
					echo "3. insert"; \
					echo "4. select"; \
					echo "5. Back"; \
					echo ""; \
					read -p "Enter your choice: " specific_choice; \
\
					case $$specific_choice in \
						1) rm -f $(TARGET_BUBBLE) ;; \
						2) rm -f $(TARGET_QUICK) ;; \
						3) rm -f $(TARGET_INSERTION) ;; \
						4) rm -f $(TARGET_SELECTION) ;; \
						5) valid_specific_choice="yes" ;; \
						*) echo "\n!! Invalid choice !!";; \
					esac; \
				done \
				;; \
			3) valid_choice="yes" ;; \
			*) echo "\n!! Invalid choice !!\n";; \
		esac; \
	done
