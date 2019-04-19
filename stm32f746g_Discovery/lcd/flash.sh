#!/usr/bin/env bash

openocd -f /usr/share/openocd/scripts/interface/stlink-v2-1.cfg -f /usr/share/openocd/scripts/target/stm32f7x.cfg -c "init" -c "reset init" -c "flash write_image erase build/lcd.elf" -c "reset" -c "shutdown"
