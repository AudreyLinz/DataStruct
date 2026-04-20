#include <iostream>
#include <unordered_map> //Hash table
#include <vector>

class HashExamples{
public:
    template<typename T>
    static void countFrequency(const std::vector<T>& v){
        std::unordered_map<T, int> freq;
        for(const T& i : v){
            freq[i]++;
        }
        for(const auto& f : freq){
            std::cout << f.first << " : " << f.second << std::endl;
        }
    }

    template<typename T>
    static bool hasDuplicates(const std::vector<T>& v){

    }
private:

};

int main(){
    std::unordered_map<std::string, int> grades;

    //insert
    grades["Michael"] = 90;
    grades["Anna"] = 85;
    grades["John"] = 76;

    //Iterate through the table
    for(const auto& grade : grades){
        std::cout << grade.first << " : " << grade.second << std::endl;
    }


    //Search (find method)
    auto it = grades.find("John");

    if(it == grades.end()){
        std::cout << "Not found\n";
    } else {
        std::cout << "Found:\n";
        std::cout << it->first << " : " << it->second << std::endl;
    }

    std::cout << "C0unt Frequency... \n";
    std::vector<int> v {1, 2, 3, 4, 1, 2, 2, 2, 5, 5, 12};
    HashExamples::countFrequency(v);

    std::cout << "C0unt Duplicates... \n";
    std::vector<int> v {"hello", "apple", "banana", "hey", "ban", "apple"};
    HashExamples::hasDuplicates(v);

    return 0;
}