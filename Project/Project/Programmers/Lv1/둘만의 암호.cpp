#include <string>

using namespace std;

string solution(string s, string skip, int index) {
    auto temp = 0;
    string answer = "";

    for (char c : s) {
        int j = 0;
        for (int i = 1; i <= index + j; i++) {
            temp = c + (i % 26);
            if (temp > 'z')
                temp += 'a' - 'z' - 1;
            
            if (skip.find(temp) != string::npos)
                j += 1;
        }
        answer.push_back(temp);
    }

    return answer;
}
