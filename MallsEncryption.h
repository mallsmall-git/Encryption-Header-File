// Version: 1.0.4
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

int choose_between(int minimum, int maximum);
std::string get_ascii_table(int start, int end);
std::string Generate_Key();
std::string encrypt_with_key(const std::string& string, const std::string& key);
std::string de_encrypt_with_key(const std::string& encrypted_string, const std::string& key);
std::string turn_str_to_bin(const std::string& string);
std::string turn_bin_to_str(const std::string& binary_string);
std::string XOR_Cipher(const std::string& string, const std::string& key);
std::string ROT13_Cipher(std::string string);
std::string Ceaser_Shift_Cipher(std::string string, int shifts);
std::string Atbash_Cipher(const std::string &string);

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

std::string encrypt_with_key(const std::string& string, const std::string& key) {
    std::string encrypted;

    for (char c : string) {
        int index_in_ascii_table = static_cast<unsigned char>(c) % 128;

        encrypted += key[index_in_ascii_table];
    }
    return encrypted;
}

std::string turn_str_to_bin(const std::string& string) {
    std::string made_bin;
    for (char c : string) {
        made_bin += std::bitset<8>(static_cast<unsigned char>(c)).to_string();
    }
    return made_bin;
}

std::string turn_bin_to_str(const std::string& binary_string) {
    std::string string;
    for (size_t i = 0; i < binary_string.length(); i += 8) {
        std::bitset<8> binary_chunk(binary_string.substr(i, 8));
        string += static_cast<unsigned char>(binary_chunk.to_ulong());
    }
    return string;
}

std::string de_encrypt_with_key(const std::string& encrypted_string, const std::string& key) {
    std::string de_encrypted_string;
    for (char c : encrypted_string) {
        int index = key.find(c, 0);
        de_encrypted_string += (unsigned char)index;
    }
    return de_encrypted_string;
}

std::string XOR_Cipher(const std::string& string, const std::string& key) {
    std::string encrypted = string;
    for (size_t i = 0; i < string.length(); i++) {
        encrypted[i] = string[i] ^ key[i % key.length()];
    }
    return encrypted;
}

std::string ROT13_Cipher(std::string string){
    std::string ROT13_ENCRYPTED_CIPHER = string;

    for (size_t i = 0; i < ROT13_ENCRYPTED_CIPHER.length(); i++){
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

std::string Ceaser_Shift_Cipher(std::string string, int shifts){
    if (shifts < 1 || shifts > 26) return "";
    std::string encrypted = string;
    for (size_t i = 0; i < string.length(); i++){
        char c = encrypted[i];
        if (c >= 'A' && c <= 'Z'){
            encrypted[i] = (c - 'A' + 13) % 26 + 'A';
        }else if (c >= 'a' && c <= 'z'){
            encrypted[i] = (c - 'a' + 13) % 26 + 'a';
        }
    }
    return encrypted;
}

std::string Atbash_Cipher(const std::string &string){
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
