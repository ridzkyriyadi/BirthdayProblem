#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<iomanip>
#include<fstream>

long double calculateProbabilityMatchingBirthday(int people) {
    long double probabilityMatchingBirthday = 0.0;
    long double probabilityNonmatchingBirthday = 0.0;
    for(int i = 0; i < people; i++){
        if(probabilityNonmatchingBirthday == 0.0) {
            probabilityNonmatchingBirthday = (365.0-i)/365.0;
        }
        else {
            probabilityNonmatchingBirthday = (365.0-i)/365.0 * probabilityNonmatchingBirthday;
        }

    }

    probabilityMatchingBirthday = 1.0 - probabilityNonmatchingBirthday;
    return probabilityMatchingBirthday;
}

std::vector<std::string> getCommaSeparatedStrings(std::string peopleString) {
    std::vector<std::string> stringVector;
    std::stringstream sStream(peopleString);
    while(sStream.good()) {
        std::string substr;
        getline(sStream, substr, ',');
        stringVector.push_back(substr);
    }

    return stringVector;
}

std::set<int> convertStringVectorToPeopleSet(std::vector<std::string> stringVector) {
    std::set<int> peopleSet;

    for(int i = 0; i < stringVector.size(); i++) {
        std::vector<std::string> stringVectorToFindRanges;
        std::stringstream sStream(stringVector.at(i));

        while(sStream.good()) {
            std::string substr;
            getline(sStream, substr, '-');
            stringVectorToFindRanges.push_back(substr);
        }

        if(stringVectorToFindRanges.size() < 2) {
            peopleSet.insert(std::stoi(stringVector.at(i)));
        }

            //This is the case to parse ranges (i.e. 1-5 converts to 1,2,3,4,5)
        else if(stringVectorToFindRanges.size() == 2) {
            int beginRange = std::stoi(stringVectorToFindRanges.at(0));
            int endRange = std::stoi(stringVectorToFindRanges.at(1));

            for(int i = beginRange; i <= endRange; i++) {
                peopleSet.insert(i);
            }
        } else {
            throw std::invalid_argument("Invalid range construct");
        }
    }

    return peopleSet;
}

std::set<int> parseInputFromUser(std::string peopleString) {
    std::set<int> peopleSet;
    if(peopleString.compare("all") == 0) {
        for(int i = 1; i <= 365; i++) {
            peopleSet.insert(i);
        }
    } else {
        std::vector<std::string> stringVector = getCommaSeparatedStrings(peopleString);
        peopleSet = convertStringVectorToPeopleSet(stringVector);
    }

    return peopleSet;
}

std::map<int, long double> retrievePeopleToProbabilityMap(std::set<int> peopleSet) {
    std::map<int, long double> peopleToProbabilityMap;
    for(auto it = peopleSet.begin(); it != peopleSet.end(); it++) {
        long double chances = calculateProbabilityMatchingBirthday(*it);
        peopleToProbabilityMap.insert(std::pair<int, long double>(*it, chances));
    }

    return peopleToProbabilityMap;
}

void outputResultsToFile(std::map<int, long double> peopleToProbabilityMap, std::string outputFile) {
    std::ofstream results;

    if(outputFile.compare("console") == 0) {
        std::cout << "Filename: Console" << std::endl << std::endl;
    } else {
        results.open(outputFile);
        results << "Filename: " << outputFile << std::endl << std::endl;
    }

    for(auto it = peopleToProbabilityMap.begin(); it != peopleToProbabilityMap.end(); it++) {
        if(outputFile.compare("console") == 0) {
            std::cout << "People: " << it->first << ", Probability: " << std::setprecision(19) << it->second << std::endl;
        } else {
            results << "People: " << it->first << ", Probability: " << std::setprecision(19) << it->second << std::endl;
        }
    }

    if(outputFile.compare("console") != 0) {
        std::cout << "Results sent to output file: " << outputFile << std::endl << std::endl;
    } else {
        std::cout << std::endl;
    }

    results.close();
}

int main() {
    int defaultPeople = 50;
    std::string peopleString = "";
    std::string outputFile = "";

    while(peopleString.compare("exit") != 0 ) {
        std::cout << "Type exit or 0 to exit program" << std::endl << "Enter one or multiple (comma separated) or ranges (ex. 1, 3-7, 3,4,7-10)"
                  << std::endl << "Enter all for all possible values" << std::endl << "If no value entered, defaulting to 50" << std::endl
                  << "Number of People: ";
        std::cin >> peopleString;
        if(peopleString.compare("exit") == 0 || peopleString.compare("0") == 0) {
            std::cout << "Exiting Program" << std::endl;
            return 0;
        }

        try {
            std::cout << "Enter file to output results.  Type console to output to console" << std::endl
                      << "Output File: ";
            std::cin >> outputFile;
            if(peopleString.compare("") == 0) {
                peopleString = std::to_string(defaultPeople);
            }

            std::set<int> peopleSet = parseInputFromUser(peopleString);

            std::map<int, long double> peopleToProbabilityMap = retrievePeopleToProbabilityMap(peopleSet);
            outputResultsToFile(peopleToProbabilityMap, outputFile);
        } catch (std::invalid_argument) {
            std::cout << "Invalid input, please enter a valid input" << std::endl << std::endl;
        }
    }

    return 0;
}

