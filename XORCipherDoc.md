Hello! Quick note that I write these docs
with my own knowledge, so please correct me
if im wrong! Thanks!

XOR (mentioned as Exclusive Or) is a bitwise logical
operation. It does the work in binary, but you
can just XOR words, letters, numbers together in
code. In C++, C, C#, F#, Java, Javascript and Typescript,
Python, Go, Ruby and PHP, the XOR command is just "^" (strings
not included). It is commonly showed as a circled plus sign.

How it works is very simple. If both XORed bits are the same, its 0,
if one of them is different, it outputs 1. 
An example (using binary bits):
0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
1 ^ 1 = 0

Now an example with letters:
A (01000001) and a (01100001):

0 ^ 0 = 0
1 ^ 1 = 0
0 ^ 1 = 1
0 ^ 0 = 0
0 ^ 0 = 0
0 ^ 0 = 0
0 ^ 0 = 0
1 ^ 1 = 0

The output is 00100000 (a space (32))
Now in XOR Ciphers normally we have a key and a
string. Lets say our string is "Hello, World!"
and our key is "k". We loop through every character
value and XOR it with our key, which is the lowercase character
"k". Here is a C++ example:
// C++ Example
#include <iostream>

using namespace std;

int main() {
    string OurStr = "Hello, World!";
    char Key = 'k';
    string EncryptedString;

    for (char c : OurStr){
        char EncryptedChar = c ^ Key;
        EncryptedString.push_back(EncryptedChar);
    }
    cout << "Encrypted String: " << EncryptedString << endl;
    return 0;
}
// C++ example end
The text might look wierd, with wierd characters but its completely normal!

The key can be as long as you want!

Now if the key is shorter than the input string, we pad it with the key itself.
Lets say our input string is "abcdefg" and our key is "ab". We pad ab with itself
until it is as big as the input string. So we pad ab to
"abababa" then we can XOR each string[i] character with key[i] character.

Now, if you tried XORing the encrypted string with the same key you will notice that its
the same old string (Hello, World!).

Thanks for reading!