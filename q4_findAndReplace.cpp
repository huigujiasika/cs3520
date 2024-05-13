#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <assert.h>

// Reverse string
std::string reverseString(const std::string& str) {
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

// meet Punctuation
bool isPunctuation(char c) {
    return (c == '!' || c == '.' || c == ',' || c == ';' || c == '"' || c == '\'' || c == '?' || c == '$' || c == ' ');
}

// Find the world all indices
std::vector<size_t> findWordIndices(const std::string& paragraph, const std::string& word) {
    std::vector<size_t> indices;
    std::string::size_type pos = paragraph.find(word);

    int wordLength = word.length();
    while (pos != std::string::npos) {
        // Avoid seeing "their" as "the"
        if (pos + wordLength < paragraph.length() && !isPunctuation(paragraph[pos + wordLength])) { 
            pos = paragraph.find(word, pos + 1);
            continue;
        }

        indices.push_back(pos);
        pos = paragraph.find(word, pos + 1);
    }
    return indices;
}

// We can't replace the word one by one. For example, when we meet the words 'dog'and 'god' in paragraph "dog meet god", 
// if we replace dog first, the result will be "dog meet dog". But the true result is "god meet dog"
std::string findAndReplaceWords(const std::string &paragraph, const std::string searchWords) {
    // Split the search string into individual words
    std::vector<std::string> words;
    std::string word;
    std::stringstream stringStream(searchWords);
    while (stringStream >> word) {
        words.push_back(word);
    }

    // Count the occurrences and store starting indices
    std::vector<std::vector<size_t>> wordIndices;
    for (const auto& word : words) {
        std::vector<size_t> indices = findWordIndices(paragraph, word);
        wordIndices.push_back(indices);
    }

    // Print the occurrences and their indices
    std::cout << std::endl << "Occurrences found:" << std::endl;
    for (size_t i = 0; i < words.size(); i++) {
        std::cout << words[i] << ": " << wordIndices[i].size() << " occurrence at index: ";
        for (const auto& index : wordIndices[i]) {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    }
    
    // Reverse the words at respective indices
    std::string replacedParagraph = paragraph;
    for (size_t i = 0; i < words.size(); i++) {
        const std::string& word = words[i];
        const std::string& reversedWord = reverseString(word);
        for (const auto& index : wordIndices[i]) {
            replacedParagraph.replace(index, word.length(), reversedWord);
        }
    }
    return replacedParagraph;
}


// Find and replace the search Sentence
std::string findAndReplaceSentense(std::string &paragraph, const std::string searchWords) {
    // Count the occurrences and their starting indices
    size_t count = 0;
    std::string::size_type pos = paragraph.find(searchWords);
    std::cout << "Occurrences found at indices: ";
    while (pos != std::string::npos) {
        std::cout << pos << " ";
        pos = paragraph.find(searchWords, pos + 1);
        count++;
    }
    std::cout << std::endl;
    std::cout << "Total occurrences: " << count << std::endl;

    // Reverse the search string
    std::string reversedSearch = reverseString(searchWords);

    // Replace occurrences with the reversed search string
    std::string replacedParagraph = paragraph;
    pos = replacedParagraph.find(searchWords);
    while (pos != std::string::npos) {
        replacedParagraph.replace(pos, searchWords.length(), reversedSearch);
        pos = replacedParagraph.find(searchWords, pos + reversedSearch.length());
    }
    return replacedParagraph;
}

int main() {
    std::string paragraph;
    std::cout << "Enter a paragraph: ";
    std::getline(std::cin, paragraph);

    int mode;
    std::cout << "Choose the mode you want to use (1: multiple words, 2:  a sentence) : ";
    std::cin >> mode;

    std::string searchWords;
    std::cout << "Enter the words or sentence to search for: ";
    std::cin.ignore();
    std::getline(std::cin, searchWords);

    std::string replacedParagraph;
    if (mode == 1) {
        replacedParagraph = findAndReplaceWords(paragraph, searchWords);
    } else {
        replacedParagraph = findAndReplaceSentense(paragraph, searchWords);
    }

    // Print the new paragraph and the old version
    std::cout << std::endl << "New paragraph: " << replacedParagraph << std::endl;
    std::cout << "Old version: " << paragraph << std::endl;

    return 0;
}