#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int point1 = 0, point2 = 0;

    for (string str : goal) {
        if (point1 < cards1.size() && cards1.at(point1).compare(str) == 0) {
            point1++;
        }
        else if (point2 < cards2.size() && cards2.at(point2).compare(str) == 0) {
            point2++;
        }
        else {
            answer = "No";
            return answer;
        }
    }

    return answer;
}
