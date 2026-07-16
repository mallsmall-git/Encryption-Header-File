// Version: 1.1.5
// Made by: mallsmall-script (in github)

/*
NOTES:

Some ciphering techniques are not recommended, and I hope that you will use this file right and use the save methods.

*/
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <string_view>



int choose_between(int minimum, int maximum);
std::string get_ascii_table(int start, int end);
std::string Generate_Key();
std::string encrypt_with_key(std::string_view string, std::string_view key);
std::string de_encrypt_with_key(std::string_view encrypted_string, std::string_view key);
std::string turn_str_to_bin(std::string_view string);
std::string turn_bin_to_str(const std::string &binary_string);
std::string XOR_Cipher(const std::string& string, std::string_view key, const bool ReturnASCIIValue = false);
std::string ROT13_Cipher(std::string string);
std::string Caesar_Shift_Cipher(const std::string string, int shifts);
std::string Atbash_Cipher(std::string_view string);
std::string Base64_Encoding(std::string_view string);

static std::random_device rd;
static std::mt19937 gen(rd());

// FUNCS
int choose_between(int minimum, int maximum) {
    std::uniform_int_distribution<int> distrib(minimum, maximum);
    return distrib(gen);
}

std::string get_ascii_table(int start, int end){
    std::string letters_in_ASCII_table_accordingly;
    for (int i = start; i < end; i++){
        letters_in_ASCII_table_accordingly += (unsigned char)i;
    }
    return letters_in_ASCII_table_accordingly;
}

std::string Generate_Key() {
    std::vector<int> made_randoms;
    std::string key;

    while (key.length() < 128) {
        std::uniform_int_distribution<int> distrib(0, 127);
        int random = distrib(gen);

        if (std::find(made_randoms.begin(), made_randoms.end(), (unsigned char)random) != made_randoms.end()) {

        }
        else {
            key += (unsigned char)random;
            made_randoms.push_back((unsigned char)random);
        }
    }
    return key;
}

std::string encrypt_with_key(std::string_view string, std::string_view key) {
    std::string encrypted;

    for (char c : string) {
        int index_in_ascii_table = static_cast<unsigned char>(c) % 128;

        encrypted += key[index_in_ascii_table];
    }
    return encrypted;
}

std::string turn_str_to_bin(std::string_view string) {
    std::string made_bin;
    for (char c : string) {
        made_bin += std::bitset<8>(static_cast<unsigned char>(c)).to_string();
    }
    return made_bin;
}

std::string turn_bin_to_str(const std::string &binary_string) {
    std::string string;
    for (size_t i = 0; i < binary_string.length(); i += 8) {
        std::bitset<8> binary_chunk(binary_string.substr(i, 8));
        string.push_back(static_cast<unsigned char>(binary_chunk.to_ulong()));
    }
    return string;
}

std::string de_encrypt_with_key(std::string_view encrypted_string, std::string_view key) {
    std::string de_encrypted_string;
    for (char c : encrypted_string) {
        int index = key.find(c, 0);
        de_encrypted_string += (unsigned char)index;
    }
    return de_encrypted_string;
}


/**
 * The ReturnASCIIValue is for debugging only. It is not recommended to use it unless you want to see the ASCII values of the returning string.
 * The space or tab or null or enter etc... values can be seen this way.
 */
std::string XOR_Cipher(const std::string& string, std::string_view key, const bool ReturnASCIIValue) {

    if (key.empty()) {
        throw std::invalid_argument("Key cannot be empty!");
    }

    std::string encrypted;
    if (!ReturnASCIIValue) {encrypted.reserve(string.length());}

    for (size_t i = 0; i < string.length(); i++) {
        char Character = string[i] ^ key[i % key.length()];
        if (!ReturnASCIIValue){
            encrypted.push_back(Character);
        }else if (ReturnASCIIValue){
            encrypted += std::to_string(static_cast<unsigned int>(static_cast<unsigned char>(Character)));
        }
    }
    return encrypted;
}

std::string ROT13_Cipher(std::string string){
    std::string ROT13_ENCRYPTED_CIPHER = string;

    for (size_t i = 0; i < ROT13_ENCRYPTED_CIPHER.length(); ++i){
        char c = ROT13_ENCRYPTED_CIPHER[i];// 
        if (c >= 'A' && c <= 'Z'){
            ROT13_ENCRYPTED_CIPHER[i] = (c - 'A' + 13) % 26 + 'A';
        }
        if (c >= 'a' && c <= 'z'){
            ROT13_ENCRYPTED_CIPHER[i] = (c - 'a' + 13) % 26 + 'a';
        }
    }
    return ROT13_ENCRYPTED_CIPHER;
}

std::string Caesar_Shift_Cipher(const std::string string, int shifts){
    shifts = (shifts % 26 + 26) % 26;
    std::string encrypted;
    encrypted.reserve(string.length());
    for (char c : string){
        if (c >= 'A' && c <= 'Z'){
            encrypted.push_back((c - 'A' + shifts) % 26 + 'A');
        }else if (c >= 'a' && c <= 'z'){
            encrypted.push_back((c - 'a' + shifts) % 26 + 'a');
        }else{
            encrypted.push_back(c);
        }
    }
    return encrypted;
}

std::string Atbash_Cipher(std::string_view string){
    std::string encrypted;
    for (char c : string){
        if (c >= 'A' && c <= 'Z'){
            encrypted += (unsigned char)'Z' - (c - 'A');
        }else if (c >= 'a' && c <= 'z'){
            encrypted += (unsigned char)'z' - (c - 'a');
        }else{
            encrypted += c;
        }
    }
    return encrypted;
}

std::string Base64_Encoding(std::string_view string){
    if (string == "") return "";
    static const std::string Base64_Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string made_binary;
    made_binary.reserve(string.size() * 8);
    for (char c : string) {
        made_binary += std::bitset<8>(static_cast<unsigned char>(c)).to_string();
    }
    std::string BinaryChunk;
    std::vector<std::string> BinaryChunks;
    int loops = 0;
    std::string ReturningBase64;
    int NumberOfZerosAdded = 0;
    for (char BinC : made_binary){
        if (loops >= 6){
            loops = 0;
            
            
            BinaryChunks.push_back(BinaryChunk);
            BinaryChunk.clear();
        }
        BinaryChunk.push_back(BinC);
        loops += 1;
    }

    if (!BinaryChunk.empty()){
        BinaryChunks.push_back(BinaryChunk);
    }

    for (std::string BinChunk : BinaryChunks){
        while (BinChunk.length() < 6){
            if (BinChunk.length() >= 6) break;
            BinChunk.push_back('0');
            NumberOfZerosAdded += 1;
        }
        uint64_t num = 0;
        for (char c : BinChunk){
            num = (num << 1) | (c - '0');
        }
        ReturningBase64.push_back(Base64_Chars[num]);
    }
    size_t remainder = string.size() % 3;
    if (remainder == 1) ReturningBase64 += "==";
    else if (remainder == 2) ReturningBase64.push_back('=');
    return ReturningBase64;
}
