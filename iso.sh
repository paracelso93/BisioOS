
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/bisios.kernel isodir/boot/bisios.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "bisios" {
    multiboot /boot/bisios.kernel
}
EOF
grub-mkrescue -o bisios.iso isodir
