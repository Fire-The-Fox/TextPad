include config.mk

help:
	@echo
	@echo "TextPad build options":
	@echo "'make clean' to clean build directory and revert changes to defaults"
	@echo "'make build' to build TextPad but not install it"
	@echo "'make install' build and install TextPad ( requires sudo )" 
	@echo "'make uninstall' to uninstall TextPad ( requires sudo )"
	@echo

build:
	@echo 
	@echo "Started building"
	mkdir bin
	cp config.def.h config.h
	$(GCC) TextPad.c $(CFLAGS)
	@echo "Building is complete"
	@echo

clean:
	@echo
	@echo "Cleaning TextPad build directory"
	rm -rf bin
	rm -f config.h
	@echo "TextPad was reverted to defaults"
	@echo

install: clean build
	@echo
	@echo "Installing TextPad"
	cp ./bin/TextPad $(DESTDIR)$(BIN_PATH)
	@echo "TextPad is installed"
	@echo

uninstall:
	@echo
	@echo "Uninstalling TextPad"
	rm $(DESTDIR)$(BIN_PATH)/TextPad
	@echo "TextPad was uninstalled"
	@echo
