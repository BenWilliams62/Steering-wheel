# Qt

## Download isntructions

Instructions for macOS only. This is how i did it but the official downloads and documentation can be found [here] (https://wiki.qt.io/Building_Qt_5_from_Git#Getting_the_source_code)

1. In the terminal, download the source code
> git clone git://code.qt.io/qt/qt5.git
> cd qt5
> git checkout 5.12
> perl init-repository

2. Make a build directory
> mkdir qt5-build && cd qt5-build
> ../configure -developer-build -opensource -nomake examples -nomake tests -confirm-license

3. Trigger the build
> make -j$(nproc)

4. 