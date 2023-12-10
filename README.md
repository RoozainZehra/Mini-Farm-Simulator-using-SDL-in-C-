- For Windows:
	`g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf`
- For MacOS:
  	`clang++ *.cpp -I/Library/Frameworks/SDL2.framework/Headers -I/Libaray/Frameworks/SDL2_image.framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_image`
  
- Run the game by this command:
	- For Windows:
	`.\a.exe`

	- For MacOS:
 	`./a.out`

Through the testing phase of our project, we have noticed a pattern of errors that may arise due to the SDL library we are using. Below are errors that may be encountered at compilation stage and their possible solutions. These have been tried and tested.
- Always make sure the main function takes (int argc, char* argv[]) as an argument
- `C:/mingw_dev_lib/mingw/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/8.1.0/../../../../x86_64-w64-mingw32/lib/../lib/libmingw32.a(lib64_libmingw32_a-crt0_c.o):crt0_c.c:(.text.startup+0x2e): undefined reference to `WinMain``
  To solve this error, rename the main(int argc, char* argv[]) function as WinMain(int argc, char* argv[])
- `C:/mingw_dev_lib/mingw/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/8.1.0/../../../../x86_64-w64-mingw32/lib/../lib/libmingw32.a(lib64_libmingw32_a-crt0_c.o):crt0_c.c:(.text.startup+0x2e): undefined reference to `SDL_Main``
  To solve this error, rename the main(int argc, char* argv[]) function as SDL_Main(int argc, char* argv[])
