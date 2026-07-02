from os import path

Import("env")

platform = env.PioPlatform()
openocd_scripts = path.join(platform.get_package_dir("tool-openocd"), "scripts")

env.Replace(
    UPLOADER="openocd",
    UPLOADERFLAGS=[
        "-s", openocd_scripts,
        "-f", "interface/stlink.cfg",
        "-c", "transport select hla_swd",
        "-c", "set CHIPNAME at91samd21e18",
        "-c", "set CPUTAPID 0x0bc11477",
        "-f", "target/at91samdXX.cfg",
        "-c", "init",
        "-c", "reset halt",
        # "-c", "at91samd bootloader 0", # sets BOOTPROT fuse
    ],
    UPLOADCMD='$UPLOADER $UPLOADERFLAGS -c "program {$SOURCE} 0x0 verify reset; shutdown;"',
)