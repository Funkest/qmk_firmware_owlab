#!/bin/bash
make -r -R -C ./ -f builddefs/build_keyboard.mk  KEYBOARD=funkest/me02 KEYMAP=default SILENT=false $*
