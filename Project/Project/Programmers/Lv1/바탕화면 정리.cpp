#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer{ 50, 50, -1, -1 };
    int temp1 = 0;
    int temp2 = 0;
    vector<char>::iterator iter;
    for (int i = 0; i < wallpaper.size(); i++) {
        temp1 = wallpaper[i].find("#");
        if (temp1 != string::npos) {
            answer[0] = min(answer[0], i);
            answer[1] = min(answer[1], temp1);
            answer[2] = max(answer[2], i + 1);
            answer[3] = max(answer[3], temp1 + 1);
        }
        temp2 = wallpaper[i].rfind("#");
        if (temp1 != temp2) {
            if (temp2 != string::npos) {
                answer[0] = min(answer[0], i);
                answer[1] = min(answer[1], temp2);
                answer[2] = max(answer[2], i + 1);
                answer[3] = max(answer[3], temp2 + 1);
            }
        }
    }

    return answer;
}
