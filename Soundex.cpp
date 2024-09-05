#include "Soundex.h"
#include <cctype>
#include <string>
#include <unordered_map>
#include <iostream>

std::unordered_map<char, char> buildSoundexMap() {
    return {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, 
        {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
}

char getSoundexCode(char c) {
    static std::unordered_map<char, char> soundexMap = buildSoundexMap();
    c = toupper(c);
    
    if (soundexMap.find(c) != soundexMap.end()) {
        return soundexMap[c];
    }

    return '0';
}

void addValidSoundexCode(std::string& soundex, char& prevCode, char currentCode) {
    if (currentCode != '0' && currentCode != prevCode) {
        soundex += currentCode;
        prevCode = currentCode;
    }
}

void processNameForSoundex(const std::string& name, std::string& soundex, char& prevCode) {
    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char currentCode = getSoundexCode(name[i]);
        addValidSoundexCode(soundex, prevCode, currentCode);
    }
}

std::string generateCoreSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    processNameForSoundex(name, soundex, prevCode);

    return soundex;
}

void padSoundexCode(std::string& soundex) {
    while (soundex.length() < 4) {
        soundex += '0';
    }
}

std::string generateSoundex(const std::string& name) {
    std::string coreSoundex = generateCoreSoundex(name);
    if (coreSoundex.length() != 0){
    padSoundexCode(coreSoundex);
    }
    return coreSoundex;
}

int main(){
    std::string name = "";
    std::cout<<generateSoundex(name);
}