# What Is This Project?
This project is a simple renderer made in C++ with Vulkan.



# GOAL
A Spinning, Shaded(PBR), Textured 3D Model, in a example scene with a Free Cam controller.



# BUILD
## NON-OS Specific
Useful Setup [link](https://vulkan-tutorial.com/Development_environment)

[Vulkan SDK](https://vulkan.lunarg.com/)

## Linux
Vulkan SDK install:
```bash
# Debian
sudo apt install vulkan-tools &&
sudo apt install libvulkan-dev &&
sudo apt install vulkan-validationlayers spirv-tools
```

```bash
# Fedora
sudo dnf install vulkan-tools &&
sudo dnf install vulkan-loader-devel &&
sudo dnf install mesa-vulkan-drivers vulkan-validation-layers-devel
```

*Install all of these packages on Arch
```bash
# Arch
sudo pacman -S vulkan-devel
```

To check that the SDK installed correctly run:
```Bash
vkcube
```
or/and
```Bash
vulkaninfo
```
readme/pictures/vkcube.png
====================================================================================================

X11 and XFree86-VidModeExtension (Window):
```bash
# Debain
sudo apt install libxxf86vm-dev
sudo apt install libxi-dev
```
```bash
# Fedora
dnf install libXxf86vm-devel
dnf install libXi-devel
```

## Windows



# Credits
This project is based off of [this](https://vulkan-tutorial.com/) tutorial.



# License

[MIT](https://choosealicense.com/licenses/mit/)