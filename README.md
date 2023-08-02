# Terrarium Test

This is firmware for testing an assembled
[PedalPCB Terrarium](https://www.pedalpcb.com/product/pcb351/).
It reports the state of all controls over
[USB serial](https://electro-smith.github.io/libDaisy/md_doc_2md_2__a2___getting-_started-_serial-_printing.html)
and [SWD](http://www.embedded-communication.com/en/misc/printf-with-st-link/).
In addition, knobs 4 and 6 control the brightness of LEDs 1 and 2 respectively,
and the audio input is duplicated at the output.

## Build

    cmake \
        -GNinja \
        -DTOOLCHAIN_PREFIX=/path/to/toolchain \
        -DCMAKE_TOOLCHAIN_FILE=lib/libDaisy/cmake/toolchains/stm32h750xx.cmake \
        -DCMAKE_BUILD_TYPE=Release \
        -B build .
    cmake --build build
