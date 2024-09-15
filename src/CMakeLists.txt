add_executable(edu-embedded)

set_target_properties(edu-embedded
    PROPERTIES
        OUTPUT_NAME "image.elf")

target_sources(edu-embedded
    PRIVATE
        main.c)

add_custom_command(TARGET edu-embedded
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary image.elf image.bin)
