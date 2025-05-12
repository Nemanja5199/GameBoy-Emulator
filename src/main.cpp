#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[])
{
    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    // Create a window
    SDL_Window* window = SDL_CreateWindow("Game Boy Emulator Test",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        640, 576,
                                        SDL_WINDOW_SHOWN);
    
    if(!window){
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    
    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    
    // Set background color to green and clear
    SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    
    // Wait for 3 seconds
    std::cout << "SDL test running! Window should be visible for 3 seconds." << std::endl;
    SDL_Delay(3000);
    
    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    std::cout << "SDL test completed successfully!" << std::endl;
    return 0;
}
