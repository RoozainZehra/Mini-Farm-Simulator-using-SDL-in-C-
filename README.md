- For Windows:
	`g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf`
- For MacOS:
  	`clang++ *.cpp -I/Library/Frameworks/SDL2.framework/Headers -I/Libaray/Frameworks/SDL2_image.framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_image`
  
- Run the game by this command:
	- For Windows:
	`.\a.exe`

	- For MacOS:
 	`./a.out`
