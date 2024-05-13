#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

void readParagraph(std::string &paragraph) {    
    std::string line;
    std::getline(std::cin, line);
    paragraph = line;
}

int countParagraphWords(const std::string &paragraph) {
    std::stringstream stringStream(paragraph);
    int count = 0;

    std::string word;
    while (stringStream >> word) {
        count++;
    }
    return count;
}

// determine if the letter is a vowel
bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
 
void countVowelsAndConsonants(const std::string& paragraph, int& vowelCount, int& consonantCount) {
    vowelCount = 0;
    consonantCount = 0;

    for (char c : paragraph) {
        if (!std::isalpha(c)) {
            continue;
        }
        if (isVowel(c)) {
            vowelCount++;
        } else {
            consonantCount++;
        }
    }
}

int countWordsUseTwoVowels(const std::string &paragraph) {
    std::stringstream stringStream(paragraph);
    std::string world;
    int count = 0;

    while (stringStream >> world) {
        int vowelCount = 0;
        for (char c : world) {
            if (isVowel(c)) {
                vowelCount++;
            }
        }

        if (vowelCount == 2) {
            count++;
        }
    }
    return count;
}

// determine if the letter is a punctuation
bool isPunctuation(char c) {
    return (c == '!' || c == '.' || c == ',' || c == ';' || c == '"' || c == '\'' || c == '?' || c == '$');
}

int countWordsUsePunctuation(const std::string& paragraph) {
    std::stringstream stringStream(paragraph);
    std::string word;
    int count = 0;

    while (stringStream >> word) {
        for (char c : word) {
            if (isPunctuation(c)) {
                count++;
                break;
            }
        }
    }
    return count;
}


int countWordsWithLength(const std::string& paragraph, int length, bool considerPunctuation) {
    std::stringstream stringStream(paragraph);
    std::string word;
    int count = 0;

    while (stringStream >> word) {
        int wordLength = 0;

        if (considerPunctuation) {           // if considerPunctuation use word.length() function
            wordLength = word.length();
        } else {
            for (char c : word) {
                if (!isPunctuation(c)) {
                    wordLength++;
                }
            }
        }
        if (wordLength <= length) {
            count++;
        }
    }
    return count;
}

int main(int argc, char** argv) {
    std::cout << "Please enter a paragraph: " << std::endl;

    // read the whole paragraph
    std::string paragraph;
    readParagraph(paragraph);

    // calculate the number of total words in the paragraph
    int wordCount = countParagraphWords(paragraph);
    std::cout << "The number of total words in the paragraph : " << wordCount << std::endl; 

    // calculate the number of vowels and consonants used
    int vowelCount = 0, consonantCount = 0;
    countVowelsAndConsonants(paragraph, vowelCount, consonantCount);
    std::cout << "The number of vowels and consonants used : " << vowelCount << " " << consonantCount << std::endl;

    // calculate the number of words that use exactly two vowel.
    int wordTwoVowelCount = 0;
    wordTwoVowelCount = countWordsUseTwoVowels(paragraph);
    std::cout << "The number of words that use exactly two vowel : " << wordTwoVowelCount << std::endl; 

    // calculate the number of words that use any one of eight punctuation marks
    int wordUsePunctuationCount = 0;
    wordUsePunctuationCount = countWordsUsePunctuation(paragraph);
    std::cout << "The number of words that use any one of eight punctuation marks : " << wordUsePunctuationCount << std::endl; 

    // calculate the number of words with length smaller or equal to the user provided length
    std::cout << "Please enter a number(world length): ";
    int userWordLength = 0;
    std::cin >> userWordLength;
    int worldSmallerLengthCount = countWordsWithLength(paragraph, userWordLength, false);
    std::cout << "The number of words with length smaller or equal to the "<< userWordLength << " : " << worldSmallerLengthCount << std::endl; 

    // calculate the number of words with length smaller than the random length
    int randomLength = (rand() % (9 - 3 + 1)) + 3;
    int worldSmallerRandomCount = countWordsWithLength(paragraph, randomLength, true);
    std::cout << "The number of words with length smaller than the random length " << randomLength << ": " << worldSmallerRandomCount << std::endl; 

    return 0;
}   


