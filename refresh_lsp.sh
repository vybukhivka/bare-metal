#!/bin/bash

make -C bootloader clean
make -C app clean
bear -- sh -c "make -C bootloader && make -C app"
echo -e "\nRestart LSP"
