#include <iostream>
#include <fstream>
#include <string>
#include <cassert>


const int ALPHABET_LENGTH{26};

int number_from_letter(char letter) {
  int offset = letter - (int)'a';
  if (offset < 0 || offset >= ALPHABET_LENGTH) {
    std::cout << "number_from_letter called with invalid argument (" << letter << ").\n";
    assert(false);
  }
  return offset;
}

char letter_from_number(int number) {

  if (number < 0 || number >= ALPHABET_LENGTH) {
    std::cout << "letter_from_number called with an invalid argument (" << number << ").\n";
    assert(false);
  }

  const char alphabet[] = { 'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z'};
  return alphabet[number];
}
/* the program will get a plain text from an input file,
read the direction and shift number and each character of the letter the file wants to encipher and will then proceed to print as an output
the word it first read from the file but now enciphered within the conditions inside.
*/
int main() {
    char letter_direction{ 'a' };
    int number_shift;
    char plain_text{ 'a' };
    std::string cipheredtext;



    std::ifstream input_file{};
    input_file.open("input.txt");



    /* if there is not input file output an error
    *  if there is not a shift number output an error
    * if the direcction is not left or right output an error
    */

    if (!(input_file >> letter_direction)) {
        std::cout << "Oops: Could not read the direction from the input file." << "\n";
        return 0;
    }

    if (!(letter_direction == 'l' || letter_direction == 'r')) {
        std::cout << "Oops: Invalid direction in the input file.\n";
        return 0;
    }

    if (!(input_file >> number_shift)) {
        std::cout << "Oops: Could not read the shift number from the input file.\n";
        return 0;
    }


    /* get the plain text from the file, convert it to its numeric position in the alphabet
    * if the direction is left substract the shift number from the actual index
    or numeric position of the letter and use the modulo %  to get the new index or new position.
    then check is its less than 0, if it is add to the actual numeric position of the letter in the alphabet 26
    if the direction is right add the shift number to the actual position of the letter in the alphabet and use the modulo %
    */
    while (!std::iscntrl(input_file.peek()) && !input_file.eof()) {
        input_file >> plain_text;
        int letter_to_number = number_from_letter(plain_text);

        if (letter_direction == 'l') {
            letter_to_number = (letter_to_number - number_shift) % ALPHABET_LENGTH;

            if (letter_to_number < 0) {
                letter_to_number = letter_to_number + ALPHABET_LENGTH;}
            }
            else if (letter_direction == 'r') {
                letter_to_number = (letter_to_number + number_shift) % ALPHABET_LENGTH;} 
        // convert each character with its new index or position back to a letter.
             char ciphered_characters = letter_from_number(letter_to_number);
             cipheredtext += ciphered_characters;
        


      

    }// print the new ciphered text.
    std::cout << cipheredtext << "\n";
    return 0;
}
