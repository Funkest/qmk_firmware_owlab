#!/bin/bash
make -r -R -C ./ -f builddefs/build_keyboard.mk  KEYBOARD=funkest/link65 KEYMAP=default SILENT=false $*
