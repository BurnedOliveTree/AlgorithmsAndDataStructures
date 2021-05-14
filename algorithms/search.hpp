#ifndef ads_search_hpp
#define ads_search_hpp

#include <string>
#include "math.hpp"
#include "../containers/vector.hpp"

namespace ads {
    void find_naive(std::string pattern, std::string text, Vector<unsigned long>& indexes) {
        /// finds the desired pattern in text by a naive method
        unsigned long pattern_length = pattern.size();
        unsigned long text_length = text.size();
        bool pattern_if = true;

        if (pattern_length > text_length)
            return;

        for (unsigned long i = 0; i < text_length; ++i) {
            if (text_length - i >= pattern_length) {
                pattern_if = true;
                for (unsigned long j = 0; j < pattern_length; ++j)
                    if (pattern[j] != text[i + j]) {
                        pattern_if = false;
                        break;
                    }
                if (pattern_if)
                    indexes.push_back(i);
            }
        }
    }

    void make_goodList(std::string pattern, long long goodList[]) {
        /// Finds the pattern in text using the full Boyer–Moore string-search algorithm, with both heurystics.
        const unsigned long pattern_length = pattern.size();
        long long foo[pattern_length+1];
        for (long long i = 0; i < pattern_length; ++i)
            foo[i] = 0;

        // in case the matching suffix occurs earlier in the pattern
        long long i = pattern_length;
        long long j = pattern_length + 1;
        foo[i] = j;
        while (i > 0) {
            while (j <= pattern_length && pattern[i-1] != pattern[j-1]) {
                if (goodList[j] == 0)
                    goodList[j] = j - i;
                j = foo[j];
            }
            i -= 1;
            j -= 1;
            foo[i] = j;
        }

        // in case part of the matching suffix is present at the very begining of the pattern
        j = foo[0];
        for (long long i = 0; i < pattern_length; ++i) {
            if (goodList[i] == 0)
                goodList[i] = j;
            if (i == j)
                j = foo[j];
        }
    }

    void find_BoyerMoore(std::string pattern, std::string text, Vector<unsigned long>& indexes) {
        /// Finds the pattern in text using the simplified Boyer–Moore string-search algorithm using only bad character heurystics.
        const long long pattern_length = pattern.size();
        long long text_length = text.size();

        // creating badList with each letter index of last occurence
        int badList[128];
        for (int i = 0; i < 128; ++i)
            badList[i] = -1;
        for (unsigned long letter = 0; letter < pattern_length; ++letter)
            badList[pattern[letter]] = letter;

        long long goodList[pattern_length+1];
        for (unsigned long i = 0; i < pattern_length+1; ++i)
            goodList[i] = 0;
        make_goodList(pattern, goodList);

        long long text_index = 0;
        long long pattern_index;
        long long max_array[2] = {1, 1};
        while (pattern_length + text_index <= text_length) {
            pattern_index = pattern_length - 1;
            // iterate over pattern from behind while it's the same as current part of the text
            while (pattern_index > -1 && pattern[pattern_index] == text[pattern_index + text_index])
                pattern_index -= 1;
            // if we did find a bad character, we jump an according amount of signs
            if (pattern_index > -1) {
                max_array[0] = goodList[pattern_index + 1];
                max_array[1] = pattern_index - badList[text[pattern_index + text_index]];
                text_index = text_index + max(max_array, 2);
            }
            // if we didn't, we have a correct pattern and can move along
            else {
                indexes.push_back(text_index);
                text_index += goodList[0];
            }
        }
    }
}

#endif /* ads_search_hpp */