import os
import platform

buildCommandLinux = """  
                    sudo mkdir -p build/temporaryFiles &&
                    sudo mkdir -p lib
                    cd ./build/temporaryFiles &&
                    sudo cmake ../../ &&
                    sudo make
               """

buildCommandWindows = "mkdir build\project & cd build\project & cmake ../../"

if __name__== "__main__":
    if platform.system().lower() == "windows":
        os.system(buildCommandWindows)
        print("Your Visual Studio project is in build\Project.")
    elif platform.system().lower() == "linux":
        os.system(buildCommandLinux)
        print("Your executable is on build/ConfigParser.")