#!/usr/bin/env bash

openocd -f /usr/share/openocd/scripts/interface/stlink-v2.cfg -f /usr/share/openocd/scripts/target/stm32f1x.cfg -c "init" -c "reset init" -c "flash write_image erase build/blink.elf" -c "reset" -c "shutdown"
