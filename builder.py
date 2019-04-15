import os

buildCommand = """  
                    sudo mkdir -p build/temporaryFiles &&
                    sudo mkdir -p lib
                    cd ./build/temporaryFiles &&
                    sudo cmake ../../ &&
                    sudo make
               """

if __name__== "__main__":
    os.system(buildCommand)
    print("Your executable is on build/ConfigParser.")