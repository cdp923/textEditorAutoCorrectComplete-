#include "autocomplete.h"
#include "keyboardAndDictionary.h"
#include <fstream>
#include <iostream>
#include <algorithm>


std::vector<std::wstring> autoComplete(std::wstring input, std::vector<std::vector<std::wstring>>dictionary){
    std::vector<std::wstring> suggestionVector(5);
    int stringIndex =0;
    while (stringIndex<input.size()){
        input[stringIndex] = std::tolower(input[stringIndex]);
        stringIndex++;
    }
    if (input.size() <= 1 || containSymbols(input)){
        printf("return empty vector. input.size() <= 1 || containSymbols(input)");
        suggestionVector.resize(0);
        return suggestionVector;
    }
    int index = indexOfFirstChar(input);
    int suggestionsAdded =0;
    for(int count=0; count<dictionary[index].size();count++){
        //printf("%ls, ", dictGraph[index][count].c_str());
        if (input.size()<=dictionary[index][count].size()){
            if (input == dictionary[index][count].substr(0, input.size())){
                if (suggestionsAdded <suggestionVector.size()){
                    suggestionVector[suggestionsAdded] = dictionary[index][count];
                    suggestionsAdded++;
                }else{
                    break;
                }
            }
        }
    }
    suggestionVector.resize(suggestionsAdded);
    int i =0;
    while (i<suggestionVector.size()){
        printf("%ls, ", suggestionVector[i].c_str());
        i++;
    }
    return suggestionVector;
}