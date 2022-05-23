#include <SDL2/SDL_mixer.h>

void playsound() {
    Mix_Music * bgsound;
    Mix_OpenAudio(22050,AUDIO_S16SYS,2,640);
    bgsound = Mix_LoadMUS("sound/soundmp3.mp3");
    Mix_PlayMusic(bgsound, 1);
}