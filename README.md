# OOP-Project-GRP05
Relevant instructions can be found in `GRP5_L4.pdf`.

# For Windows/Mac Users
- Open the `PROJECT_GRP5` folder in VSCode.
- Open VSCode terminal and put this command to compile everything:

	For Windows: `g++ Game_basic_code.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image`

	For Mac: `clang++ Game_basic_code.cpp -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_mixer.framework/Headers -I/Libaray/Frameworks/SDL2_image.framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_image -framework SDL2_mixer`

- Run the game by this command:

	For Windows: `.\a.exe`
	For Mac: `./a.out`

# For CMake users:
There is a `CMakeLists.txt` file in the main directory. The process is exactly the same as for the previous homeworks. To build the project:
- `cd PROJECT_GRP5` (please ensure you are in a directory where this exists)
- `mkdir build` (creates a build directory inside the PROJECT folder)
- `cd build` (navigate to the newly created build director)
- On Linux use `cmake ..`. On windows use `cmake -G "MinGW Makefiles" ..` if you install gcc via MSYS2. If you installed gcc via strawberry perl, use `cmake -G "Unix Makefiles" ..`
- Run `make` or `make -j4`
