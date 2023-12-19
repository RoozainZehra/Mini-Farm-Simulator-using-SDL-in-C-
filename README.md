INTRODUCTION:
Welcome to our Mini Farm! Here, you can plant your vegetables, keep a whole lot of animals, and also engage in trade. Explore the world of farming and animal keeping (be careful! If you leave your animals hungry for too long, they may die).


HOW TO PLAY:
You will be provided with limited resources - one vegetable each and a handful of gold coins. Utilize these resources mindfully to keep a healthy and happy farm. You can interact with the patches and animal fences by bumping into them, and with the market and barn (storage) by clicking on them.
Step 1: Make sure you start by planting. Once you run out of vegetables, you can not buy them.
Step 2: Make sure you feed your animals and collect their produce on time. If an animal is left hungry for too long, your animal will die and you will lose the game.
Step 3: Make sure to routinely check your barn to see how much of each item you currently have.
Step 4: Once you collect enough goods, sell them to increase your gold coins. 
Step 5: Buy patches as you go! The more patches of land you have, the more vegetables you can plant!


HOW TO RUN:
- For Windows:
	`g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf`
- For MacOS:
  	`clang++ *.cpp -I/Library/Frameworks/SDL2.framework/Headers -I/Libaray/Frameworks/SDL2_image.framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_image`
  
- Run the game by this command:
	- For Windows:
	`.\a.exe`

	- For MacOS:
 	`./a.out`


WARNING! (Common errors we came across!)
Through the testing phase of our project, we have noticed a pattern of errors that may arise due to the SDL library we are using. Below are errors that may be encountered at compilation stage and their possible solutions. These have been tried and tested.
- Always make sure the main function takes (int argc, char* argv[]) as an argument
- `C:/mingw_dev_lib/mingw/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/8.1.0/../../../../x86_64-w64-mingw32/lib/../lib/libmingw32.a(lib64_libmingw32_a-crt0_c.o):crt0_c.c:(.text.startup+0x2e): undefined reference to `WinMain``
  To solve this error, rename the main(int argc, char* argv[]) function as WinMain(int argc, char* argv[])
- `C:/mingw_dev_lib/mingw/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/8.1.0/../../../../x86_64-w64-mingw32/lib/../lib/libmingw32.a(lib64_libmingw32_a-crt0_c.o):crt0_c.c:(.text.startup+0x2e): undefined reference to `SDL_Main``
  To solve this error, rename the main(int argc, char* argv[]) function as SDL_Main(int argc, char* argv[])
