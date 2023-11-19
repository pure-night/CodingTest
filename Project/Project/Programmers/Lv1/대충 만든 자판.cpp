#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> m;
    int sum = 0;
    int temp = 0;

    for (int i = 0; i < keymap.size(); i++) {
        for (int j = 0; j < keymap[i].length(); j++) {
            if (m[keymap[i][j]] > j + 1 || m[keymap[i][j]] == 0) {
                m[keymap[i][j]] = j + 1;
            }
        }
    }

    for (int i = 0; i < targets.size(); i++) {
        sum = 0;
        for (int j = 0; j < targets[i].length(); j++) {
            temp = m[targets[i][j]];
            if (temp == 0) {
                answer.push_back(-1);
                sum = 0;
                break;
            }
            sum += temp;
        }
        if(sum != 0)
            answer.push_back(sum);
    }

    return answer;
}
