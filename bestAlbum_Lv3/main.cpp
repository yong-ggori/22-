#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool plays_cmp(pair<string, int> g1, pair<string, int> g2);

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genres_playsTotal;                 // �帣 �� �� �÷��� Ƚ��
    map<int, vector<pair<string, int>>> genres_plays;   // �� ���� ��ȣ�� �帣 �� �÷��� Ƚ��
    vector<pair<string, int>> playsTotal;               // �帣 �� �� �÷��� Ƚ���� �������� �ϱ� ���� ����

    for (int idx = 0; idx < genres.size(); idx++) {
        genres_playsTotal[genres[idx]] += plays[idx];
        genres_plays[idx].push_back({ genres[idx], plays[idx] });
    }

    for(auto temp_plays : genres_plays)                 // ��ü�� �÷��� Ƚ���� �������� ����
        sort(temp_plays.second.begin(), temp_plays.second.end(), plays_cmp);
    
    playsTotal.assign(genres_playsTotal.begin(), genres_playsTotal.end());      // vector �Լ� assign ���� �ش� ������ ��ü
    sort(playsTotal.begin(), playsTotal.end(), plays_cmp);                      // �帣 �� �� �÷��� Ƚ���� �������� ����

    for(int idx = 0; idx < playsTotal.size(); idx++) {
        for (int jdx = 0 ; jdx < 2;) {             // �� 2���� �����ϱ� ���� �ݺ���
            if (genres_plays[idx][jdx].first == playsTotal[idx].first) {
                answer.push_back(genres_plays);
                jdx++;
            }
        }
    }

    return answer;
}

bool plays_cmp(pair<string, int> g1, pair<string, int> g2) {
    return g1.second > g2.second;
}