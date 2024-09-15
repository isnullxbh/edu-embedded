# Debugging with ReNode

## STM32F407VG (STM32F4-DISC1)

1. Build image (elf will be used).
2. Run renode
3. Create machine `mach create "test"`
4. Copy [stm32f4_custom.repl](../tools/renode/stm32f4_custom.repl) to platforms/cpus.
5. Load platform/CPU with `machine LoadPlatformDescription @platforms/cpus/stm32f4.repl` (see note)
6. Load elf `sysbus LoadELF @<path-to-binary>`
7. Start GDB server `machine StartGdbServer 3333`
8. Run GDB
9. Connect to the GDB server `target remote :3333`
10. Debug

**Single command:**

```shell
./renode \
  -e "include @platforms/cpus/stm32f4_custom.repl" \
  -e "machine StartGdbServer 3333" \
  -e "sysbus LoadELF @/home/isnullxbh/repos/edu-embedded/build/gcc-13-arm-debug/src/image.elf"
```
