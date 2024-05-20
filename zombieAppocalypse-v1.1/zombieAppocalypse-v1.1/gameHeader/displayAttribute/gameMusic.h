#ifndef gameMusic_h
#define gameMusic_h
void handleMusic (std::string musicFile) {
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        Mix_Music* music = Mix_LoadMUS(musicFile.c_str());
        Mix_PlayMusic(music, -1);
        Mix_Volume(-1, MIX_MAX_VOLUME / 4);
}

void handleSoundEffect (std::string musicFile) {
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Chunk *gunShot = Mix_LoadWAV(musicFile.c_str());
    Mix_PlayChannel(-1, gunShot, 0);
    Mix_Volume(-1, MIX_MAX_VOLUME / 4);
    Mix_CloseAudio();
}
#endif /* gameMusic_h */
