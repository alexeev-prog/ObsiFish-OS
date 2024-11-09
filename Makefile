CC = gcc
FASM = fasm

BIN_DIR = bin
SRC_DIR = src
SRC_BOOT_DIR = $(SRC_DIR)/boot

TARGET = $(BIN_DIR)/obsifish.img

build:
	@mkdir -p bin

	@echo "$(FASM)			| src/boot/bootloader.asm"
	@$(FASM) $(SRC_BOOT_DIR)/bootloader.asm $(TARGET)
