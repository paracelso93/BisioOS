# BisioOS
This OS is quite useless but you can use it.
To compile it you must create a cross compiler. For reference you can use this site: https://wiki.osdev.org/GCC_Cross-Compiler.
You basically have to configure gcc and binutils with this flags: 
--target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror for binutils and
-target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers for gcc.
Then you have to build and install them, you can run iso.sh to create an iso that you can boot or qemu.sh to boot it directly with qemu.
